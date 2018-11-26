/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/26 18:08:44 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define DOT_IS_PLAYER (f.board[n + i][x + j] == f.player || \
					f.board[n + i][x + j] == f.player + 32)
#define DOT_IS_ENEMY (f.board[n + i][x + j] == f.enemy || \
					f.board[n + i][x + j] == f.enemy + 32)

t_f			f;
t_out		out;

static size_t	get_token_begin_n(void)
{
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	j = 0;
	z = 0;
	while (i < f.tn)
	{
		j = 0;
		while (j < f.tx)
		{
			if (f.token[i][z] == '.' || f.token[i][z] == '*')
				j++;
			if (f.token[i][j] == '*')
				return (i);
			z++;
		}
		i++;
	}
	return (0);
}

//static size_t	get_token_begin_n(void)
//{
//	size_t	i;
//	size_t	j;
//
//	i = 0;
//	j = 0;
//	while (i < f.tn)
//	{
//		j = 0;
//		while (j < f.tx)
//			if (f.token[i][j] == '*')
//				return (i);
//			else
//				j++;
//		i++;
//	}
//	return (0);
//}

//static size_t	get_token_begin_x(void)
//{
//	size_t	i;
//	size_t	j;
//
//	i = 0;
//	j = 0;
//	while (j < f.tx)
//	{
//		i &= 0;
//		while (i < f.tn)
//			if (f.token[i][j] == '*')
//				return (j);
//			else
//				i++;
//		j++;
//	}
//	return (0);
//}

static int	check_position(size_t n, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	link;

	link = 0;
	i = 0;
	while (f.token[i] && i < f.tn && n + i + f.tn <= f.n)
	{
		j = 0;
		while (j < f.tx && x + j + f.tx <= f.x)
		{
			if (f.token[i][j] == '*')
			{
				if DOT_IS_ENEMY
					return (0);
				else if DOT_IS_PLAYER
					link++;
				if (link > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (link ? 1 : 0);
}

int	search_place()
{
	size_t	n;
	size_t	x;

	ft_bzero(&out, sizeof(t_out));
	out.tn = get_token_begin_n();
//	out.tx = get_token_begin_x();
	n = 0;
	while (n < f.n)
	{
		x = 0;
		while (x < f.x)
			check_position(n, x++);
		n++;
	}
	if (out.steps)
		ft_printf("%d %d\n", out.n, out.x);
	ft_arraystrfree(f.token);
	return (0);
}
