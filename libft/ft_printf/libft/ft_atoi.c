/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:46:00 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/04 17:16:56 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int res;
	int minus;

	res = 0;
	minus = 1;
	while (*s < 33)
		s++;
	if (*s == '-' || *s == '+')
		(*s++ == '-') && (minus = -1);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (res * minus);
		res = res * 10 + *s++ - 48;
	}
	return (res * minus);
}
