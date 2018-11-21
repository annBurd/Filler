/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 20:30:40 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "ft_printf.h"
// #include "libft.h"
// #include "color.h"
#include <time.h>

#define SHOW_MAP (f.quietMode && !f.interactiveMode)

typedef struct	s_f
{
	char		**board;
	size_t		n; //lines
	size_t		x; //column;
	char 		*xLine;
	char		**piece;
	size_t		dot[2];
	char 		*p1;
	char 		*p2;
	size_t		interactiveMode;	//default
	size_t		quietMode;
	size_t		time;
	size_t		seed;	//use the seed number (initialization random) (man srand)
	size_t		score1;
	size_t		score2;
}				t_f;

typedef struct	s_ox //additional
{
	short		o;
	short		x;
}				t_ox;

extern t_f		f;

int				f_exit(int code);
void			get_board(char *s);
void			print_board();
void			get_piece();
void			start_game();

#endif