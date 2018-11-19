/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/19 19:48:33 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "ft_printf.h"
// #include "libft.h"
// #include "color.h"

typedef struct	s_board
{
	char		**board;
	size_t		n; //lines
	size_t		x; //column;
	char 		*columnLine;
}				t_board;

typedef struct	s_filler
{
	t_board		b;
	char 		*p1;
	char 		*p2;
	short		i;	//interactive mode(default)
	short		q;	//quiet mode
	size_t		t;	//set timeout in second
	size_t		s;	//use the seed number (initialization random) (man srand)
	size_t		score1;
	size_t		score2;
}				t_filler;

typedef struct	s_ox //additional
{
	char		o;
	char		x;
	size_t		len;
}				t_ox;

int		fillit_exit(int code, void *p);
void	get_board(t_board *b, char *s);

void	board_crate(t_filler *b);
void	board_print(t_filler *b);

#endif