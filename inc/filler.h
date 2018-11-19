/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/17 19:38:52 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "ft_printf.h"
// #include "libft.h"
// #include "color.h"

#define F z->f

typedef struct	s_flag
{
	size_t		time;	//set timeout in second
	short		q;		//quiet mode
	short		i;		//interactive mode(default)
	char 		*p1;
	char 		*p2;
	char 		*file;	//use a map file (required)
	size_t		s;		//use the seed number (initialization random) (man srand)
}				t_flag;
	size_t		n; //lines

typedef struct	s_filler
{
	size_t		line;	// N
	size_t		column;	// X
	char		**board;
	char 		*columnLine;
	size_t		score1;
	size_t		score2;
	t_flag		f;
}				t_filler;


void	usage(void);
void	handle_flags(t_filler *, char **);


void	board_crate(t_filler *);
void	board_free(t_filler *);
void	board_print(t_filler *);

#endif