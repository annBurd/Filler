/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:00:35 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 20:20:43 by aburdeni         ###   ########.fr       */
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

void		get_board(char *s)
{
	size_t	len;
	t_ox	ox;
	int		fd;
	int		i;

	ft_bzero(&ox, sizeof(ox));
	(i = open(s, O_RDONLY)) < 0 && f_exit(-1);
	while (ft_getline(i, &f.xLine) > 0)
		f.n++;
	ft_memdel((void**)&f.xLine);
	(fd = open(s, O_RDONLY)) < 0 && f_exit(-1);
	f.board = ft_arraystrnew(f.n);
	!close(i) && (i = 0);
	while (ft_getline(fd, &f.board[i]) > 0)
	{
		!f.x && (f.x = ft_strlen(f.board[0]));
		len = ft_strlen(f.board[i]);
		(len != f.x || !valid_line(&ox, f.board[i])) && f_exit(-2);
		i++;
	}
	close(fd);
	!(ox.o && ox.x) && f_exit(-2);
}

void	print_board()
{
	size_t	i;

	i = 0;
	ft_printf("    %s\n", f.xLine);
	ft_printf("Plateau %zu %zu:\n    %s\n", f.n, f.x, f.xLine);
	while (i < f.n)
	{
		ft_printf("%03zu %s\n", i, f.board[i]);
		i++;
	}
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
	f.piece = ft_arraystrnew(f.n);
	while (ft_getline(0, &f.piece[n]) > 0)
		n++;
	if SHOW_MAP
		print_piece(n, ft_strlen(f.piece[0]));
}
