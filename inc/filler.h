/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/27 22:00:01 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
#include "../libft/gnl/get_next_line.h"
#include "color.h"
#include "ft_printf.h"

typedef struct	s_f
{
	char		**board;
	size_t		n;
	size_t		x;

	char		**token;
	size_t		tn;
	size_t		tx;

	char 		player;
	char 		enemy;

	size_t		out_n;
	size_t		out_x;
}				t_f;

typedef struct	s_out
{
	size_t		n;
	size_t		x;
	size_t		steps;
	size_t		t_n;
	size_t		t_x;
	size_t		t_n_end;
	size_t		t_x_end;
}				t_out;

extern t_f		g_f;
extern t_out	g_out;

void			search_place();
void			set_token_coord();

#endif