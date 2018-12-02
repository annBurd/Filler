/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/12/02 17:52:50 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define B(n, x) g_f.board[n][x]

t_f			g_f;
t_solve		g_solve;

static int	get_token_border_n(int n, int x)
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
			if (g_f.token[i][j] == '*')
				star = i;
			j++;
		}
		i++;
	}
	return (star);
}

static int	get_token_border_x(int n, int x)
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
			if (g_f.token[i][j] == '*')
				star = j;
			i++;
		}
		j++;
	}
	return (star);
}

static void	count_distance_to_enemy(int n, int x)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < g_f.size_b.n)
	{
		j = -1;
		while (++j < g_f.size_b.x)
			if (B(i, j) == g_f.enemy || B(i, j) == g_f.enemy + 32)
			{
				tmp = (ft_abs(i - n) + ft_abs(j - x));
				if (tmp < g_solve.steps && tmp > 0)
				{
					g_solve.steps = tmp;
					g_f.out.n = n;
					g_f.out.x = x;
				}
			}
	}
}

static int	check_position(int n, int x)
{
	int		i;
	int		j;
	short	dot;

	if (n + g_solve.border.n >= g_f.size_b.n ||
		x + g_solve.border.x >= g_f.size_b.x)
		return (0);
	dot = 0;
	i = -1;
	while (g_f.token[++i])
	{
		j = -1;
		while (g_f.token[i][++j])
			if (g_f.token[i][j] == '*')
			{
				if (B(n + i, x + j) == g_f.player ||
					B(n + i, x + j) == g_f.player + 32)
					dot++;
				if (B(n + i, x + j) == g_f.enemy ||
					B(n + i, x + j) == g_f.enemy + 32 || dot > 1)
					return (0);
			}
	}
	return (dot ? 1 : 0);
}

void		search_place(void)
{
	int	n;
	int	x;

	ft_bzero(&g_solve, sizeof(t_solve));
	g_solve.steps = g_f.size_b.n + g_f.size_b.x;
	g_solve.border.n = get_token_border_n(g_f.size_token.n, g_f.size_token.x);
	g_solve.border.x = get_token_border_x(g_f.size_token.n, g_f.size_token.x);
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
}
