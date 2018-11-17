/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 20:20:36 by aburdeni          #+#    #+#             */
/*   Updated: 2017/11/28 20:20:39 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static void		*ft_strarfree(char **str)
{
	while (*str)
	{
		free(&str);
		str++;
	}
	free(str);
	return (NULL);
}

static size_t	ft_strarlen(char const *s, char c)
{
	size_t	line;

	line = 0;
	while (*(s++))
		if (*(s - 1) != c && (*s == c || *s == 0))
			line++;
	return (line);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	n;
	size_t	line;

	if (!s || !c ||
		!(array = (char**)malloc(sizeof(char*) * (ft_strarlen(s, c) + 1))))
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
				return (ft_strarfree(array));
			array[line] = ft_strncpy(array[line], (s - n), n);
			n = 0;
			line++;
		}
	}
	array[line] = (char*)0;
	return (array);
}
