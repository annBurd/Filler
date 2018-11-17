/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_descending_order.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 21:28:07 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/16 21:28:07 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_descending_order(int *tab, int size)
{
	int i;

	i = 0;
	while (++i < size)
		if (tab[i - 1] < tab[i])
			return (0);
	return (1);
}