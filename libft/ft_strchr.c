/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:40:41 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/21 19:18:59 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ss;

	ss = (char*)s;
	while (*ss)
		if (*(ss++) == c)
			return (ss - 1);
	return (c == 0) ? ss : NULL;
}