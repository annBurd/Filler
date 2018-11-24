/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/23 22:16:57 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			f;

static size_t	get_token_begin_n(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < f.tn)
	{
		j &= 0;
		while (j < f.tx)
			if (f.token[i][j] == '*')
				return (i);
			else
				j++;
		i++;
	}
	return (0);
}

static size_t	get_token_begin_x(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < f.tx)
	{
		i &= 0;
		while (i < f.tn)
			if (f.token[i][j] == '*')
				return (j);
			else
				i++;
		j++;
	}
	return (0);
}

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

static void	update_board(char *line, size_t i)
{
	if (!f.board)
	{
		while (ft_getline(0, &line) > 0 && !ft_strstr(line, "Plateau"))
			if (ft_strstr(line, "exec") && ft_strstr(line, "aburdeni.filler"))
			{
				f.player = (char)(ft_strstr(line, "p1") ? 'O' : 'X');
				f.enemy = (char)(f.player == 'X' ? 'O' : 'X');
			}
		f.board = get_array(line, &f.n, &f.x);
		while (i < f.n)
			f.board[i++] = ft_strnew(f.x);
		ft_getline(0, &line);
	}
	else
		while (i++ < 3 && ft_getline(0, &line))
			;
	i = 0;
	while (ft_getline(0, &line) > 0 && i < f.n && !ft_strstr(line, "Piece"))
		ft_strcpy(f.board[i++], line + 4);
	f.token = get_array(line, &f.tn, &f.tx);
	i = 0;
	while (i < f.tn && ft_getline(0, &f.token[i]) > 0)
		i++;
}

int			main(void)
{
	static char	*line;

	ft_bzero(&f, sizeof(t_f));
	while (1)
	{
		update_board(line, 0);
		f.t[0] = get_token_begin_n();
		f.t[1] = get_token_begin_x();
		if (!(search_place()))
			break ;
		ft_arraystrfree(f.token);
	}
	ft_arraystrfree(f.board);
	ft_arraystrfree(f.token);
	free(line);
	return (0);
}
