/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:00:35 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/19 19:49:11 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static int 	valid_line(t_ox *ox, const char *s)
{
	while(*s)
	{
		if (*s == 'X')
		{
			if (!ox->x)
				ox->x = 1;
			else
				return (0);
		}
		else if (*s == 'O')
		{
			if (!ox->o)
				ox->o = 1;
			else
				return (0);
		}
		else if (*s != '.')
			return (0);
		s++;
	}
	return (1);
}

static char	*generate_columnLine(size_t size)
{
	char	*fresh;
	size_t	i;

	fresh = (char*)malloc(sizeof(char) * (size));
	fresh[size] = 0;
	i = 0;
	while (i < size)
	{
		fresh[i] = (char)(i % 10 + '0');
		i++;
	}
	return (fresh);
}

void		get_board(t_board *b, char *s)
{
	char 	*line;
	int 	fd;
	size_t	i;
	t_ox	ox;

	b->n = 0;
	(fd = open(s, O_RDONLY)) < 0 && fillit_exit(-1, NULL);
	while (ft_getline(fd, &line) > 0)
		b->n++;
	close(fd);
	b->board = (char**)malloc(sizeof(char*) * b->n);
	fd = open(s, O_RDONLY);
	i = 0;
	b->x = 0;
	ft_bzero(&ox, sizeof(ox));
	while (ft_getline(fd, &line) > 0)
	{
		b->x ? (ox.len = ft_strlen(line)) : (b->x = ft_strlen(line));
		ox.len != b->x && !valid_line(&ox, line) && fillit_exit(-2, &b->board);
		b->board[i] = ft_strcpy((char*)malloc(sizeof(char) * b->x), line);
		i++;
	}
	close(fd);
	b->columnLine = generate_columnLine(b->x);
}

void	board_print(t_board *b)
{
	size_t	i;

	i = 0;
	ft_printf("    %s\n", b->columnLine);
	while (i < b->n)
	{
		ft_printf("%03zu %s\n", i, b->board[i]);
		i++;
	}
	//output Piece
}
