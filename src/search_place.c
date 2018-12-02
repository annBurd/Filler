/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/30 02:41:03 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define CUR_N (n + i - g_out.t_n)
#define CUR_X (x + j - g_out.t_x)

t_f				g_f;
t_out			g_out;

static void		count_distance_to_enemy(int n, int x)
{
	int	i;
	int	j;
	int	tmp;

//	dprintf(2, "count_distance_to_enemy before\n");
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
					g_f.out_x = ((int)x - (int)g_out.t_x < 0) ? 0 : x - g_out.t_x; //rewrite
//					dprintf(2, "== distance- spets %d\n", g_out.steps);
					dprintf(2, "== out_n (%d) = n(%d) - t_n(%d)\n", g_f.out_n, n, g_out.t_n);
					dprintf(2, "== out_x (%d) = x(%d) - t_x(%d)\n", g_f.out_x, x, g_out.t_x);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
//	dprintf(2, "count_distance_to_enemy after\n");
}

static int		check_position(int n, int x)
{
	int	i;
	int	j;
	short	dot;

//	dprintf(2, "check_position before\n");
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
//	dprintf(2, "check_position after\n");
	return (dot ? 1 : 0);
}

int		valid_position(int n, int x)
{
	int	i;
	int	j;
	short	dot;


//	dprintf(2, "valid_position before\n");
	if((n + g_out.t_n_end >= 0 || x + g_out.t_x_end >= 0) && (n + g_out.t_n_end >= g_f.n || x + g_out.t_x_end >= g_f.x))
		return (0);
	i = 0;
	dot = 0;
	while (g_f.token[i])
	{
		j = 0;
		while (g_f.token[i][j])
		{
//			dprintf(2, "valid (%d,%d)(%d,%d)\n", n, i, x, j);
//			dprintf(2, "valid (%d,%d)\n", n+i, x+j);
			if (g_f.token[i][j] == '*')
			{
				if PLAYER_DOT(n + i, x + j)
					dot++;
				if (ENEMY_DOT(n + i, x + j) || dot > 1)
					return (0);
//				dprintf(2, "valid star end (%d,%d)\n", n+i, x+j);
			}
			j++;
		}
		i++;
	}
//	dprintf(2, "valid_position after\n");
	dot && dprintf(2, "dot = %d\n", dot);
	return (dot ? 1 : 0);
}

void			search_place()
{
	int	n;
	int	x;

//	dprintf(2, "search_place before\n");
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

//	dprintf(2, "search_place after\n");
	if (!valid_position(g_f.out_n, g_f.out_x))
	{
//		dprintf(2, "reserch start\n");
		//	dprintf(2, "(%d,%d) (%d,%d)\n", g_out.t_n, g_out.t_x, g_out.t_n_end, g_out.t_x_end);
		if (!try_put_around(g_f.out_n, g_f.out_x, 1, 1))
			try_put_in_token_distance(g_f.out_n, g_f.out_x, g_f.tn, g_f.tx);

		dprintf(2, "reserch end\n");
	}
}
