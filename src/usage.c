/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:55:38 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 17:07:22 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f		f;

void	print_board()
{
	size_t	i;

	i = 0;
	ft_printf("    %s\n", f.xLine);
	ft_printf("Plateau %zu %zu:\n    %s\n", f.n, f.x, f.xLine);
	while (i < f.n)
	{
		ft_printf("%03zu %s\n", i, f.board[i]);
		i++;
	}
}
