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
t_out			g_out;

static size_t	get_n(void)
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

static size_t	get_x(void)
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

static size_t	get_n_end(void)
{
	size_t	i;
	size_t	j;
	size_t	star;

	i = 0;
	j = 0;
	star = 0;
	while (i < g_f.tn)
	{
		j = 0;
		while (j < g_f.tx)
		{
			if (g_f.token[i][j] == '*')
				star = i;
			j++;
		}
		i++;
	}
	return (star);
}

static size_t	get_x_end(void)
{
	size_t	i;
	size_t	j;
	size_t	star;

	i = 0;
	j = 0;
	star = 0;
	while (j < g_f.tx)
	{
		i = 0;
		while (i < g_f.tn)
		{
			if (g_f.token[i][j] == '*')
				star = j;
			i++;
		}
		j++;
	}
	return (star);
}

inline void		set_token_coord(void)
{
	ft_bzero(&g_out, sizeof(t_out));
	g_out.steps = g_f.n + g_f.x;
	g_out.t_n = get_n();
	g_out.t_x = get_x();
	g_out.t_n_end = get_n_end();
	g_out.t_x_end = get_x_end();
}
