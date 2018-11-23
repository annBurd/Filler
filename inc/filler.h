/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/23 18:24:16 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "color.h"
#include "ft_printf.h"
#include <time.h>

typedef struct	s_f
{
	char		**board;
	size_t		n; //lines
	size_t		x; //column;

	char		**token;
	size_t		tn; //lines
	size_t		tx; //column;
	size_t		t[2];

	size_t		out[2];

	char 		player;
	char 		enemy;
}				t_f;

//typedef struct	s_ox //additional
//{
//	short		o;
//	short		x;
//}				t_ox;

extern t_f		f;

//void			get_info();
void			refresh_info();



int				f_exit(int code);
void			refresh_board();
int				search_place();
void			get_board(/*char *s*/);
//void			get_token();


#endif