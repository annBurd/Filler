/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:00:35 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/17 19:22:29 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static char *generate_columnLine(size_t size)
{
	char	*fresh;
	size_t	i;

	fresh = (char*)malloc(sizeof(char) * (size + 1));
	fresh[size] = 0;
	i = 0;
	while (i < size)
	{
		fresh[i] = (char)(i % 10 + '0');
		i++;
	}
	return (fresh);
}

void	board_crate(t_filler *z)
{
	char	**fresh;
	size_t	i;

	fresh = (char**)malloc(sizeof(char*) * z->line);
	i = 0;
	while (i < z->line)
	{
		fresh[i] = (char*)malloc(sizeof(char) * z->column);
		ft_memset(fresh[i], '.', z->column);
		i++;
	}
	z->board = fresh;
	z->columnLine = generate_columnLine(z->column);
}

void	board_free(t_filler *z)
{
	size_t	i;

	i = 0;
	while (i < z->line)
		free(z->board[i++]);
	free(z->board);
	free(z->columnLine);
}

void	board_print(t_filler *z)
{
	size_t	i;

	i = 0;
	ft_printf("%*.d %s\n", 3, 0, z->columnLine);
	while (i < z->line)
	{
		ft_printf("%0*zu %s\n", 3, i, z->board[i]);
		i++;
	}
}
