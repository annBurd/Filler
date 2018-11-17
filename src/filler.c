/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/17 19:05:44 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int	main(int argc, char **argv)
{
	t_filler	z;

	argc == 1 ? usage() : handle_flags(&z, ++argv);

	ft_printf(CYA"Just test Makefile\n"RESET);
	return (0);
}