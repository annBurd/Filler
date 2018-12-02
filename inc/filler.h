/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/12/02 15:22:29 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "../libft/gnl/get_next_line.h"
#include "color.h"
#include "ft_printf.h"

#define F g_f
#define N g_f.size_b.n
#define X g_f.size_b.x
#define UPPER g_solve.token_u
#define BOTTOM g_solve.token_b

#define CUR_N (n + i - g_solve.token_u.n)
#define CUR_X (x + j - g_solve.token_u.x)

#define ENEMY_DOT(n, x) (g_f.board[n][x] == g_f.enemy || \
							g_f.board[n][x] == g_f.enemy + 32)
#define PLAYER_DOT(n, x) (g_f.board[n][x] == g_f.player || \
							g_f.board[n][x] == g_f.player + 32)

#define STAR(i, j) (g_f.token[i][j] == '*')

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
	t_coord		token_u; //upper left dot
	t_coord		token_b; //bottom right dot
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