/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/23 17:55:29 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define DOT_IS_PLAYER (f.board[n + i][x + j] == f.player || \
					f.board[n + i][x + j] == f.player + 32)
#define DOT_IS_ENEMY (f.board[n + i][x + j] == f.enemy || \
					f.board[n + i][x + j] == f.enemy + 32)

t_f			f;

void	add_token(size_t n, size_t x)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < f.tn)
	{
		j = 0;
		while (j < f.tx)
		{
			if (f.token[i][j] == '*')
				f.board[n + i][x + j] = (char)(f.player + 32);
			j++;
		}
		i++;
	}
}

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

	n = 0;
	while (n < f.n)
	{
		x = 0;
		while (x < f.x)
		{
			if (check_position(n, x))
				add_token(n, x);
			x++;
		}
		n++;
	}
	ft_arraystrfree(f.token);
	return (0);
}
