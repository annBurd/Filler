/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/26 18:27:35 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			g_f;

static char	**get_array(const char *s, size_t *n, size_t *x)
{
	char	**fresh;
	size_t	i;

	i = 0;
	while (s[i] && !ft_isdigit(s[i]))
		i++;
	while (s[i] && s[i] != ' ')
		*n = *n * 10 + s[i++] - '0';
	i++;
	while (s[i] && s[i] != ':')
		*x = *x * 10 + s[i++] - '0';
	fresh = (char**)malloc(sizeof(char*) * (*n + 1));
	fresh[*n] = 0;
	return (fresh);
}

static void	update_board(char *line)
{
	size_t	i;

	i = 0;
	if (!g_f.board)
	{
		g_f.board = get_array(line, &g_f.n, &g_f.x);
		while (i < g_f.n)
			g_f.board[i++] = ft_strnew(g_f.x);
	}
	i = 0;
	while (i < g_f.n && ft_getline(0, &line) > 0)
		ft_strcpy(g_f.board[i++], line + 4);
}

static void	update_token(char *line)
{
	size_t	i;

	g_f.token = get_array(line, &g_f.tn, &g_f.tx);
	i = 0;
	while (i < g_f.tn && ft_getline(0, &g_f.token[i]) > 0)
		i++;
}

int			main(void)
{
	static char	*line;

	ft_bzero(&g_f, sizeof(t_f));
	while (ft_getline(0, &line) > 0)
	{
		if (ft_strstr(line, "exec") && ft_strstr(line, "aburdeni.filler"))
		{
			g_f.player = (char)(ft_strstr(line, "p1") ? 'O' : 'X');
			g_f.enemy = (char)(g_f.player == 'X' ? 'O' : 'X');
		}
		else if (ft_strstr(line, "Plateau"))
			update_board(line);
		else if (ft_strstr(line, "Piece"))
		{
			update_token(line);
			search_place();
		}
	}
	ft_arraystrfree(g_f.board);
	if (g_f.token)
		ft_arraystrfree(g_f.token);
	free(line);
	return (0);
}
