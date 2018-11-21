/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraystrnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:43:22 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 19:43:22 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char **ft_arraystrnew(size_t size)
{
	char **fresh;

	fresh = (char**)malloc(sizeof(char*) * (size + 1));
	ft_bzero(&fresh, sizeof(fresh));
	return (fresh);
}
