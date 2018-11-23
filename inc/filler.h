/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:49:01 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/23 22:11:31 by aburdeni         ###   ########.fr       */
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

extern t_f		f;

int				search_place();

#endif