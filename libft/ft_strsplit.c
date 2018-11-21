/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:20:36 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/19 17:59:39 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	**get_array(char const *s, char c)
{
	size_t	line;
	char 	**fresh;

	line = 0;
	while (*(s++))
		if (*(s - 1) != c && (*s == c || *s == 0))
			line++;
	if (!(fresh = (char**)malloc(sizeof(char*) * (line + 1))))
		return (NULL);
	fresh[line] = 0;
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	n;
	size_t	line;

	if (!s || !c || !(array = get_array(s, c)))
		return (NULL);
	n = 0;
	line = 0;
	while (*(s++))
	{
		if (*(s - 1) != c)
			n++;
		if (*(s - 1) != c && (*s == c || *s == 0))
		{
			if (!(array[line] = ft_strnew(n + 1)))
			{
				ft_arraystrfree(array);
				break ;
			}
			array[line] = ft_strncpy(array[line], (s - n), n);
			n = 0;
			line++;
		}
	}
	return (array);
}
