/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:15:53 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/29 20:56:52 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f				g_f;
t_solve			g_solve;

static int	get_ul_n(int n, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < x)
		{
			if IS_STAR(i, j)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

static int	get_ul_x(int n, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < x)
	{
		i = 0;
		while (i < n)
		{
			if IS_STAR(i, j)
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

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
			if IS_STAR(i, j)
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
			if IS_STAR(i, j)
				star = j;
			i++;
		}
		j++;
	}
	return (star);
}

inline void		set_token_coord(void)
{
	ft_bzero(&g_solve, sizeof(t_solve));
	g_solve.steps = F.size_b.n + F.size_b.x;
	g_solve.token_ul.n = get_ul_n(F.size_t.n, F.size_t.x);
	g_solve.token_ul.x = get_ul_x(F.size_t.n, F.size_t.x);
	g_solve.token_br.n = get_br_n(F.size_t.n, F.size_t.x);
	g_solve.token_br.x = get_br_x(F.size_t.n, F.size_t.x);
}
