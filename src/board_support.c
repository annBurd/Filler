/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:00:35 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 18:53:46 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			f;

static int	valid_line(t_ox *ox, const char *s)
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

static void	generate_columnLine()
{
	size_t	i;

	f.xLine = (char*)malloc(sizeof(char) * (f.x));
	f.xLine[f.x] = 0;
	i = 0;
	while (i < f.x)
	{
		f.xLine[i] = (char)(i % 10 + '0');
		i++;
	}
}

void		get_board(char *s)
{
	char 	*line;
	size_t	i;
	t_ox	ox;

	ft_bzero(&ox, sizeof(ox));
	(ox.fd0 = open(s, O_RDONLY)) < 0 && f_exit(-1);
	while (ft_getline(ox.fd0, &line) > 0)
		f.n++;
	(ox.fd1 = open(s, O_RDONLY)) < 0 && f_exit(-1);
	f.board = ft_arraystrnew(f.n);
	i = 0;
	while (ft_getline(ox.fd1, &f.board[i]) > 0)
	{
		!f.x && (f.x = ft_strlen(f.board[0]));
		ox.len = ft_strlen(f.board[i]);
		(ox.len != f.x || !valid_line(&ox, f.board[i])) && f_exit(-2);
		i++;
	}
	close(ox.fd0);
	close(ox.fd1);
	!(ox.o && ox.x) && f_exit(-2);
	generate_columnLine();
}

static void	print_piece(size_t n, size_t x)
{
	size_t	i;

	i = 0;
	ft_printf("Piece %zu %zu:", n, x);
	while (i < n && f.piece[i])
		write(1, f.piece[i++], x);
}

void		get_piece()
{
	size_t	n;

	n = 0;
	f.piece = (char**)malloc(sizeof(char*) * f.n);
	ft_bzero(&f.piece, sizeof(f.piece));
	while (ft_getline(0, &f.piece[n]) > 0)
		n++;
	if (f.quietMode && !f.interactiveMode)
		print_piece(n, ft_strlen(f.piece[0]));
}
