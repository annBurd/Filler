/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/12/02 14:44:47 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "../libft/gnl/get_next_line.h"
#include "color.h"
#include "ft_printf.h"

#define F g_f
//#define OUT g_solve
#define ENEMY_DOT(n, x) (g_f.board[n][x] == g_f.enemy || \
							g_f.board[n][x] == g_f.enemy + 32)
#define PLAYER_DOT(n, x) (g_f.board[n][x] == g_f.player || \
							g_f.board[n][x] == g_f.player + 32)
#define IS_STAR(i, j) (g_f.token[i][j] == '*')

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
	t_coord		token_upper_left;
	t_coord		token_bottom_right;
	int			steps;
}				t_solve;

extern t_f		g_f;
extern t_solve	g_solve;

void			search_place();
void			set_token_coord();
int				valid_position(int n, int x);
int				try_put_around(int n, int x, int nDist, int xDist);
int				try_put_in_token_distance(int n, int x, int nDist, int xDist);

#endif