/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/12/02 17:04:09 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "../libft/gnl/get_next_line.h"
#include "color.h"
#include "ft_printf.h"

#define N g_f.size_b.n
#define X g_f.size_b.x

#define ENEMY_DOT(n, x) (g_f.board[n][x] == g_f.enemy || \
							g_f.board[n][x] == g_f.enemy + 32)
#define PLAYER_DOT(n, x) (g_f.board[n][x] == g_f.player || \
							g_f.board[n][x] == g_f.player + 32)

typedef struct	s_coord
{
	int 		n;
	int 		x;
}				t_coord;

typedef struct	s_f
{
	char		**board;
	t_coord		size_b;

	char		**token;
	t_coord		size_t;

	char 		player;
	char 		enemy;

	t_coord		out;
}				t_f;

typedef struct	s_solve
{
	t_coord		border;
	int			steps;
}				t_solve;

extern t_f		g_f;

void			search_place();

#endif