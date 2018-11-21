/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 17:16:38 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "ft_printf.h"
// #include "libft.h"
// #include "color.h"

typedef struct	s_f
{
	char		**board;
	size_t		n; //lines
	size_t		x; //column;
	char 		*xLine;
	char		**piece;
	char 		*p1;
	char 		*p2;
	short		i;	//interactive mode(default)
	short		q;	//quiet mode
	size_t		t;	//set timeout in second
	size_t		s;	//use the seed number (initialization random) (man srand)
	size_t		score1;
	size_t		score2;
}				t_f;

typedef struct	s_ox //additional
{
	char		o;
	char		x;
	size_t		len;
}				t_ox;

extern t_f		f;

int				f_exit(int code);
void			get_board(char *s);
void			print_board();
void			get_piece();

#endif