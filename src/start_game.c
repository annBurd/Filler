/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:02:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 20:30:40 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			f;

static void	generate_columnLine()
{
	size_t	i;

	f.xLine = (char*)malloc(sizeof(char) * (f.x + 1));
	f.xLine[f.x] = 0;
	i = 0;
	while (i < f.x)
	{
		f.xLine[i] = (char)(i % 10 + '0');
		i++;
	}
}

static int	search_place()
{
//	size_t	i;
//	size_t	j;
	while ()
	{
	}
	ft_arraystrfree(f.piece);
	return (1);
}

void		start_game()
{
//	ft_printf("launched %s\n", f.p1); //????
	if SHOW_MAP
		generate_columnLine();
	while (1)
	{
		get_piece();
		if (!(search_place()))
			break ;
		if SHOW_MAP
			print_board();
	}
	if (f.xLine)
		free(f.xLine);
}
