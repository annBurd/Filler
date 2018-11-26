/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/26 19:34:07 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "libft.h"
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
}				t_f;

typedef struct	s_out
{
	size_t		n;
	size_t		x;
	size_t		steps;
	size_t		tn;
	size_t		tx;
}				t_out;

extern t_f		g_f;
//extern t_out	g_out;

int				search_place();

#endif