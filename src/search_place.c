/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/27 18:31:45 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define ENEMY_DOT(n, x) (g_f.board[n][x] == g_f.enemy || \
							g_f.board[n][x] == g_f.enemy + 32)
#define PLAYER_DOT(n, x) (g_f.board[n][x] == g_f.player || \
							g_f.board[n][x] == g_f.player + 32)
#define CUR_N (n + i - g_out.t_n)
#define CUR_X (x + j - g_out.t_x)

t_f			g_f;
t_out		g_out;

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
		i = 0;
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

static void	count_distance_to_enemy(size_t n, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	dprintf(2, "count dist on b(%zu %zu)\n", n, x);
	i = n;
	j = x;
	while (i < g_f.n)
	{
		while (j < g_f.x)
		{
			if ENEMY_DOT(i, j)
			{
				tmp = ft_abs((int)(i - n)) + ft_abs((int)(j - x));
				if (tmp < g_out.steps)
				{
					g_out.steps = tmp;
					g_out.n = n;
					g_out.x = x;
//					dprintf(2, "== distance: in (%zu, %zu) - spets %zu - out (%zu,%zu)\n", n, x, g_out.steps, g_out.n, g_out.x);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static int	check_position(size_t n, size_t x)
{
	size_t	i;
	size_t	j;
	int		dot;

	dot = 0;
	i = g_out.t_n;

//	dprintf(2, "=== check b(%zu, %zu)\n", n, x);
	while (g_f.token[i] /*&& CUR_N + g_f.tn <= g_f.n*/)
	{
		j = g_out.t_x;
		while (g_f.token[i][j] /*&& CUR_X + g_f.tx <= g_f.x*/)
		{
			if (g_f.token[i][j] == '*' && CUR_N < g_f.n && CUR_X < g_f.x)
			{
//				dprintf(2, "CUR w/ star (%zu, %zu)\n", CUR_N, CUR_X);
				if ENEMY_DOT(CUR_N, CUR_X)
					return (0);
				else if PLAYER_DOT(CUR_N, CUR_X)
				{
					dprintf(2, "= player dot on b(%zu, %zu)\n", n, x);
					dprintf(2, "= player dot on b(%zu, %zu) cur\n", CUR_N, CUR_X);
					dot++;
				}
				if (dot > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (dot);
}

void			search_place()
{
	size_t	n;
	size_t	x;

	ft_bzero(&g_out, sizeof(t_out));
	g_out.t_n = get_token_begin_n();
	g_out.t_x = get_token_begin_x();
	g_out.steps = g_f.n + g_f.x;

	dprintf(2, "====== token_begin t(%zu, %zu)\n", g_out.t_n, g_out.t_x);
	int i = -1;
	while (++i < (int)g_f.tn)
		dprintf(2, "%s\n", g_f.token[i]);
	dprintf(2, "\n");

	n = 0;
	while (g_f.board[n])
	{
		x = 0;
		while (g_f.board[n][x])
		{
			if (check_position(n, x))
			{
				dprintf(2, "=== check dist b(%zu, %zu)\n", n, x);
				count_distance_to_enemy(n, x);
			}
			x++;
		}
		n++;
	}
//	ft_printf("%d %d\n", g_out.n, g_out.x);
//	ft_putnbr_fd(g_out.n, 1);
//	ft_putchar_fd(' ', 1);
//	ft_putnbr_fd(g_out.x, 1);
//	ft_putchar_fd('\n', 1);
	dprintf(1, "%zu %zu\n", g_out.n, g_out.x);
}
