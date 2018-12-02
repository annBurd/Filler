/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/12/02 17:10:35 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			g_f;

static char	**get_array(char const *line, int *n, int *x)
{
	char	**fresh;

	line = ft_strchr(line, ' ');
	*n = ft_atoi(line);
	line += ft_nbrlen(*n, 10) + 1;
	*x = ft_atoi(line);
	fresh = (char**)malloc(sizeof(char*) * (*n + 1));
	fresh[*n] = 0;
	return (fresh);
}

static void	update_board(char *line)
{
	int	i;

	if (!g_f.board)
	{
		i = 0;
		g_f.board = get_array(line, &g_f.size_b.n, &g_f.size_b.x);
		while (i < g_f.size_b.n)
			g_f.board[i++] = ft_strnew(g_f.size_b.x);
	}
	i = 0;
	get_next_line(0, &line);
	while (i < g_f.size_b.n && get_next_line(0, &line) > 0)
		ft_strcpy(g_f.board[i++], line + 4);
}

static void	update_token(char *line)
{
	int	i;

	if (g_f.token)
		ft_arraystrfree(g_f.token);
	g_f.size_token.n = 0;
	g_f.size_token.x = 0;
	g_f.token = get_array(line, &g_f.size_token.n, &g_f.size_token.x);
	i = 0;
	while (i < g_f.size_token.n && get_next_line(0, &g_f.token[i]) > 0)
		i++;
}

int			main(void)
{
	static char	*line;

	ft_bzero(&g_f, sizeof(t_f));
	while (get_next_line(0, &line) > 0)
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
			dprintf(1, "%d %d\n", g_f.out.n, g_f.out.x);
		}
	}
	ft_arraystrfree(g_f.board);
	if (g_f.token)
		ft_arraystrfree(g_f.token);
	free(line);
	return (0);
}
