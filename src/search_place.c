/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/29 22:27:02 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define CUR_N (n + i - g_out.t_n)
#define CUR_X (x + j - g_out.t_x)

t_f				g_f;
t_out			g_out;

static void		count_distance_to_enemy(size_t n, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = n;
	j = x;
	while (i < g_f.n)
	{
		while (j < g_f.x)
		{
			if ENEMY_DOT(i, j)
			{
				tmp = ft_abs((int)(i - n)) + ft_abs((int)(j - x));
				if (tmp < g_out.steps && tmp)
				{
					g_out.steps = tmp;
					g_f.out_n = n - g_out.t_n;
					g_f.out_x = x - g_out.t_x;
//					dprintf(2, "== distance- spets %zu\n", g_out.steps);
//					dprintf(2, "== out_n (%zu) = n(%zu) - t_n(%zu)\n", g_f.out_n, n, g_out.t_n);
//					dprintf(2, "== out_x (%zu) = x(%zu) - t_x(%zu)\n", g_f.out_x, x, g_out.t_x);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static int		check_position(size_t n, size_t x)
{
	size_t	i;
	size_t	j;
	short	dot;

	dot = 0;
	i = g_out.t_n;
	while (g_f.token[i] && CUR_N + g_out.t_n_end < g_f.n)
	{
		j = g_out.t_x;
		while (g_f.token[i][j] && CUR_X + g_out.t_x_end < g_f.x)
		{
			if (g_f.token[i][j] == '*' && CUR_N < g_f.n && CUR_X < g_f.x)
			{
				if ENEMY_DOT(CUR_N, CUR_X)
					return (0);
				else if PLAYER_DOT(CUR_N, CUR_X)
					dot++;
				if (dot > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (dot ? 1 : 0);
}

int		valid_position(size_t n, size_t x)
{
	size_t	i;
	size_t	j;
	short	dot;

	if (n + g_out.t_n_end >= g_f.n || x + g_out.t_x_end >= g_f.x)
		return (0);
	i = 0;
	dot = 0;
	while (g_f.token[i])
	{
		j = 0;
		while (g_f.token[i][j])
		{
			if (g_f.token[i][j] == '*')
			{
				if ENEMY_DOT(n + i, x + j)
				{
//					dprintf(2, "valid 2\n");
					return (0);
				}
				else if PLAYER_DOT(n + i, x + j)
					dot++;
				if (dot > 1)
				{
//					dprintf(2, "valid 3\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (dot ? 1 : 0);
}

void			search_place()
{
	size_t	n;
	size_t	x;

	set_token_coord();
	n = 0;
	while (g_f.board[n])
	{
		x = 0;
		while (g_f.board[n][x])
		{
			if (check_position(n, x))
				count_distance_to_enemy(n, x);
			x++;
		}
		n++;
	}
	if (!valid_position(g_f.out_n, g_f.out_x))
	{
//		sleep(1);
		dprintf(2, "reserch (%zu,%zu)\n", g_f.out_n, g_f.out_x);
		//	dprintf(2, "(%zu,%zu) (%zu,%zu)\n", g_out.t_n, g_out.t_x, g_out.t_n_end, g_out.t_x_end);
		try_put_around(g_f.out_n + 1, g_f.out_x + 1);
//		if (!try_put_around(g_f.out_n + 1, g_f.out_x + 1))
//			try_another_place();
	}
}
