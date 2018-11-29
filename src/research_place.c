/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:14:19 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/29 22:23:53 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int	is_enemy_around(int n, int x)
{
	int	enemy;
	int	i;
	int	j;

	enemy = 0;
	i = n - 1;
	j = x - 1;
	while (i <= n + 1)
	{
		while (j <= x + 1)
		{
			if ENEMY_DOT(i, j)
				enemy++;
			j++;
		}
		i++;
	}
	return (enemy);
}
static int	choose_one_of(int bar[9][3], int n)
{
	int	b;
	int	e;

	dprintf(2, "choose_one_of\n");
	b = 0;
	g_f.out_n = (size_t)bar[b][0];
	g_f.out_x = (size_t)bar[b][1];
	e = bar[b][2];
	b++;
	while (b < n)
	{
		if (e < bar[b][2])
		{
			g_f.out_n = (size_t)bar[b][0];
			g_f.out_x = (size_t)bar[b][1];
			e = bar[b][2];
		}
		b++;
	}
	return (1);
}

int			try_put_around(int n, int x)
{
	int	i;
	int	j;
	int	bar[8][3];
	int	b;

	ft_bzero(&bar, sizeof(bar));
	b = 0;
	i = n - 2;
	while (i <= n && i < (int)g_f.n)
	{
		j = x - 2;
		while (j <= x && j < (int)g_f.x)
		{
			if (valid_position((size_t)i, (size_t)j))
			{
				dprintf(2, "oops (%d,%d)\n", i, j);
				bar[b][0] = i;
				bar[b][1] = j;
				bar[b++][2] = is_enemy_around(i, j);
			}
			j++;
		}
		i++;
	}
	return (b ? choose_one_of(bar, b) : 0);
}
