/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/23 19:04:21 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			f;

static void	set_token_dot_start(size_t i, size_t j)
{
	while (i < f.tn)
	{
		j &= 0;
		while (j < f.tx)
			if (f.token[i][j++] == '*')
			{
				f.t[0] = i;
				break ;
			}
		i++;
	}
	j &= 0;
	while (j < f.tx)
	{
		i &= 0;
		while (i < f.tn)
			if (f.token[i++][j] == '*')
			{
				f.t[1] = j;
				break ;
			}
		j++;
	}
}

static void	get_token(char *line, size_t i)
{
	f.tn = (size_t)ft_atoi(line + 6);
	f.tx = (size_t)ft_atoi(line + 7 + ft_nbrlen(f.tn, 10));
	f.token = ft_arraystrnew(f.tn);
	while (ft_getline(0, &line) > 0 && i < f.tn)
		f.token[i++] = ft_strcpy(ft_strnew(f.tx), line);
	set_token_dot_start(0, 0);
}

static void	get_info(size_t i)
{
	static char	*line;

	if (!f.board)
	{
		while (ft_getline(0, &line) > 0 && line[0] != 'P')
			if (ft_strstr(line, "aburdeni.filler"))
			{
				f.player = (char)(line[10] == '1' ? 'O' : 'X');
				f.enemy = (char)(f.player == 'X' ? 'O' : 'X');
			}
		f.n = (size_t)ft_atoi(line + 8);
		f.x = (size_t)ft_atoi(line + 9 + ft_nbrlen(f.n, 10));
		f.board = ft_arraystrnew(f.n);
		f.board[f.n] = 0;
		while (ft_getline(0, &line) > 0 && i < f.n && line[0] != 'P')
			f.board[i++] = ft_strcpy(ft_strnew(f.x), line + 4);
	}
	else
		while (ft_getline(0, &line) > 0 && i < f.n && line[0] != 'P')
			ft_strcpy(f.board[i++], line + 4);
	get_token(line, 0);
	free(line);
}

int			main(void)
{
	ft_bzero(&f, sizeof(t_f));
	while (1)
	{
		get_info(0);
		if (!(search_place()))
			break ;
		ft_arraystrfree(f.token);
	}
	ft_arraystrfree(f.board);
	ft_arraystrfree(f.token);
	ft_printf(RED"Filler's end\n"RESET);
	return (0);
}
