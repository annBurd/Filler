/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:14:19 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/30 02:38:40 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int	is_enemy_around(int n, int x, int nDist, int xDist)
{
	int	enemy;
	int	i;
	int	j;

	enemy = 0;
	i = n - nDist;
	j = x - xDist;
	while (i <= n + nDist)
	{
		while (j <= x + xDist)
		{
			if ENEMY_DOT(i, j)
				enemy++;
			j++;
		}
		i++;
	}
	return (enemy);
}
static int	choose_one_of_bar_1(int bar[8][3], int n)
{
	int	b;
	int	e;

	b = 0;
	g_f.out_n = bar[b][0];
	g_f.out_x = bar[b][1];
	e = bar[b][2];
	b++;
	while (b < n)
	{
		if (e < bar[b][2])
		{
			g_f.out_n = bar[b][0];
			g_f.out_x = bar[b][1];
			e = bar[b][2];
		}
		b++;
	}
	dprintf(2, "(1) has been choosen one of bar (end)\n");
	return (1);
}

int			try_put_around(int n, int x, int nDist, int xDist)
{
	int	i;
	int	j;
	int	bar[8][3];
	int	b;

	ft_bzero(&bar, sizeof(bar));
	b = 0;
	i = n - nDist;
	while (i < n + nDist && i < (int)g_f.n)
	{
		j = x - xDist;
		while (j < x + xDist && j < (int)g_f.x)
		{
			if (valid_position(i, j))
			{
				bar[b][0] = i;
				bar[b][1] = j;
				bar[b++][2] = is_enemy_around(i, j, nDist, xDist);
			}
			j++;
		}
		i++;
	}
	return (b ? choose_one_of_bar_1(bar, b) : 0);
}

static int	choose_one_of_bar_token(int **bar, int n)
{
	int	b;
	int	e;

//	dprintf(2, "choose_one_of b = %d\n", n);
	b = 0;
	g_f.out_n = bar[b][0];
	g_f.out_x = bar[b][1];
	e = bar[b][2];
	b++;
	dprintf(2, "choose_one_of start while\n");
	while (b < n)
	{
		if (e < bar[b][2])
		{
			dprintf(2, "choose_one_of refresh\n");
			g_f.out_n = bar[b][0];
			g_f.out_x = bar[b][1];
			e = bar[b][2];
			free(bar[b]);
		}
		b++;
	}
	dprintf(2, "(token) has been choosen one of bar (end)\n");
	return (1);
}

int			try_put_in_token_distance(int n, int x, int nDist, int xDist)
{
	int			i;
	int			j;
	const int	nBar = (n + nDist) * (x + xDist) - 1;
	int			**bar;
	int			b;

	sleep(1);
	dprintf(2, "(token) ________ now on out (%d,%d)\n", g_f.out_n, g_f.out_x);

	dprintf(2, "(token) nBar __ %d\n", nBar);
	bar = (int**)malloc(sizeof(int*) * (nBar));
//	ft_bzero(&bar, sizeof(bar));
	b = 0;
	i = n - nDist;
	while (i < n + nDist && i < (int)g_f.n)
	{
		j = x - xDist + 1;
		while (j < x + xDist && j < (int)g_f.x)
		{
			dprintf(2, "(token)oops (%d,%d)\n", i, j);
			if (valid_position(i, j))
			{
				dprintf(2, "malloc * 3, b = %d\n", b);
				bar[b] = (int*)malloc(sizeof(int) * 3);
//				ft_bzero(&bar[b], sizeof(int) * 3);
				dprintf(2, "(int*)malloc(sizeof(int) * 3 (%d,%d)\n", i, j);
				bar[b][0] = i;
				bar[b][1] = j;
				bar[b++][2] = is_enemy_around(i, j, nDist, xDist);
			}
			j++;
		}
		i++;
	}
	b && choose_one_of_bar_token(bar, b);
	free(bar);
	return (b ? 1 : 0);
}
