/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/26 17:39:30 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			f;

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
	if (!f.board)
	{
		f.board = get_array(line, &f.n, &f.x);
		while (i < f.n)
			f.board[i++] = ft_strnew(f.x);
	}
	i = 0;
	while (i < f.n && ft_getline(0, &line) > 0)
		ft_strcpy(f.board[i++], line + 4);
}

static void	update_token(char *line)
{
	size_t	i;

	f.token = get_array(line, &f.tn, &f.tx);
	i = 0;
	while (i < f.tn && ft_getline(0, &f.token[i]) > 0)
		i++;
}

int			main(void)
{
	static char	*line;

	ft_bzero(&f, sizeof(t_f));
	while (ft_getline(0, &line) > 0)
	{
		if (ft_strstr(line, "exec") && ft_strstr(line, "aburdeni.filler"))
		{
			f.player = (char)(ft_strstr(line, "p1") ? 'O' : 'X');
			f.enemy = (char)(f.player == 'X' ? 'O' : 'X');
		}
		else if (ft_strstr(line, "Plateau"))
			update_board(line);
		else if (ft_strstr(line, "Piece"))
		{
			update_token(line);
			search_place();
		}
	}
	ft_arraystrfree(f.board);
	if (f.token)
		ft_arraystrfree(f.token);
	free(line);
	return (0);
}
