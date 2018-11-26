/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/26 19:34:07 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define DOT_IS_ENEMY (g_f.board[n + i][x + j] == g_f.enemy || \
					g_f.board[n + i][x + j] == g_f.enemy + 32)
#define DOT_IS_PLAYER (g_f.board[n + i][x + j] == g_f.player || \
					g_f.board[n + i][x + j] == g_f.player + 32)

t_f			g_f;
t_out		g_out;

static void	count_distance_to_enemy(size_t n, size_t x)
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
			if DOT_IS_ENEMY
			{
				tmp = ft_abs((int)(i - n)) + ft_abs((int)(j - x));
				if (tmp > g_out.steps)
				{
					g_out.steps = tmp;
					g_out.n = i;
					g_out.x = j;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void	check_position(size_t n, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	link;

	link = 0;
	i = 0;
	while (i < g_f.tn && n + i + g_f.tn <= g_f.n)
	{
		j = 0;
		while (j < g_f.tx && x + j + g_f.tx <= g_f.x)
		{
			if (g_f.token[i][j] == '*')
			{
				if DOT_IS_ENEMY
					return ;
				else if DOT_IS_PLAYER
					link++;
				if (link > 1)
					return ;
			}
			j++;
		}
		i++;
	}
	if (link)
		count_distance_to_enemy(n, x);
}

static size_t	get_token_begin_n(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < g_f.tn)
	{
		j = 0;
		while (j < g_f.tx)
		{
			if (g_f.token[i][j] == '*')
				return (i);
			j++;
		}
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
	while (j < g_f.tx)
	{
		i &= 0;
		while (i < g_f.tn)
		{
			if (g_f.token[i][j] == '*')
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

int	search_place()
{
	size_t	n;
	size_t	x;

	ft_bzero(&g_out, sizeof(t_out));
	g_out.tn = get_token_begin_n();
	g_out.tx = get_token_begin_x();
	n = 0;
	while (n < g_f.n)
	{
		x = 0;
		while (x < g_f.x)
			check_position(n, x++);
		n++;
	}
	if (g_out.steps)
		ft_printf("%d %d\n", g_out.n, g_out.x);
	ft_arraystrfree(g_f.token);
	return (0);
}
