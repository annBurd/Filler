/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:19:17 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/01 16:19:19 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	i = (n < 0) ? -n : n;
	if (n < 0)
		ft_putchar('-');
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}
