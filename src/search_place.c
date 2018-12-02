/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/12/02 16:48:03 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f				g_f;
t_solve			g_solve;

static int	get_br_n(int n, int x)
{
	int	i;
	int	j;
	int	star;

	i = 0;
	j = 0;
	star = 0;
	while (i < n)
	{
		j = 0;
		while (j < x)
		{
			if STAR(i, j)
				star = i;
			j++;
		}
		i++;
	}
	return (star);
}

static int	get_br_x(int n, int x)
{
	int	i;
	int	j;
	int	star;

	i = 0;
	j = 0;
	star = 0;
	while (j < x)
	{
		i = 0;
		while (i < n)
		{
			if STAR(i, j)
				star = j;
			i++;
		}
		j++;
	}
	return (star);
}

static void		count_distance_to_enemy(int n, int x)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < X)
		{
			if ENEMY_DOT(i, j)
			{
				tmp = (ft_abs(i - n) + ft_abs(j - x));
				if (tmp < g_solve.steps && tmp > 0)
				{
					g_solve.steps = tmp;
					F.out.n = n;
					F.out.x = x;
				}
			}
		}
	}
}

static int		check_position(int n, int x)
{
	int		i;
	int		j;
	short	dot;

	if (n + g_solve.token_b.n >= N || x + g_solve.token_b.x >= X)
		return (0);
	dot = 0;
	i = -1;
	while (F.token[++i])
	{
		j = -1;
		while (F.token[i][++j])
		{
			if (F.token[i][j] == '*')
			{
				if PLAYER_DOT(n + i, x + j)
					dot++;
				if (ENEMY_DOT(n + i, x + j) || dot > 1)
					return (0);
			}
		}
	}
	return (dot ? 1 : 0);
}

void			search_place()
{
	int	n;
	int	x;

	ft_bzero(&g_solve, sizeof(t_solve));
	g_solve.steps = F.size_b.n + F.size_b.x;
	g_solve.token_b.n = get_br_n(F.size_t.n, F.size_t.x);
	g_solve.token_b.x = get_br_x(F.size_t.n, F.size_t.x);
	n = 0;
	while (F.board[n])
	{
		x = 0;
		while (F.board[n][x])
		{
			if (check_position(n, x))
				count_distance_to_enemy(n, x);
			x++;
		}
		n++;
	}
}
