/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/29 23:25:16 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "../libft/gnl/get_next_line.h"
#include "color.h"
#include "ft_printf.h"

#define ENEMY_DOT(n, x) (g_f.board[n][x] == g_f.enemy || \
							g_f.board[n][x] == g_f.enemy + 32)
#define PLAYER_DOT(n, x) (g_f.board[n][x] == g_f.player || \
							g_f.board[n][x] == g_f.player + 32)

typedef struct	s_f
{
	char		**board;
	int			n;
	int			x;

	char		**token;
	int			tn;
	int			tx;

	char 		player;
	char 		enemy;

	int		out_n;
	int		out_x;
}				t_f;

typedef struct	s_out
{
	int		n;
	int		x;
	int		steps;
	int		t_n;
	int		t_x;
	int		t_n_end;
	int		t_x_end;
}				t_out;

extern t_f		g_f;
extern t_out	g_out;

void			search_place();
void			set_token_coord();
int				valid_position(int n, int x);
int				try_put_around(int n, int x, int nDist, int xDist);
int				try_put_in_token_distance(int n, int x, int nDist, int xDist);

#endif