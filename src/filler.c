/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/12/02 15:06:12 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			g_f;

static char	**get_array(char const *line, int *n, int *x)
{
	char	**fresh;

	line = ft_strchr(line, ' ');
	*n = ft_atoi(line);
	line += ft_nbrlen(*n, 10) + 1;
	*x = ft_atoi(line);
	fresh = (char**)malloc(sizeof(char*) * (*n + 1));
	fresh[*n] = 0;
	return (fresh);
}

static void	update_board(char *line)
{
	int	i;

	if (!F.board)
	{
		i = 0;
		F.board = get_array(line, &F.size_b.n, &F.size_b.x);
		while (i < F.size_b.n)
			F.board[i++] = ft_strnew(F.size_b.x);
	}
	i = 0;
	get_next_line(0, &line);
	while (i < F.size_b.n && get_next_line(0, &line) > 0)
		ft_strcpy(F.board[i++], line + 4);
}

static void	update_token(char *line)
{
	int	i;

	if (F.token)
		ft_arraystrfree(F.token);
	F.size_t.n = 0;
	F.size_t.x = 0;
	F.token = get_array(line, &F.size_t.n, &F.size_t.x);
	i = 0;
	while (i < F.size_t.n && get_next_line(0, &F.token[i]) > 0)
		i++;
}

int			main(void)
{
	static char	*line;

	ft_bzero(&g_f, sizeof(t_f));
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "exec") && ft_strstr(line, "aburdeni.filler"))
		{
			F.player = (char)(ft_strstr(line, "p1") ? 'O' : 'X');
			F.enemy = (char)(F.player == 'X' ? 'O' : 'X');
		}
		else if (ft_strstr(line, "Plateau"))
			update_board(line);
		else if (ft_strstr(line, "Piece"))
		{
			update_token(line);
			search_place();
			dprintf(1, "%d %d\n", F.out.n, F.out.x);
		}
	}
	ft_arraystrfree(F.board);
	if (F.token)
		ft_arraystrfree(F.token);
	free(line);
	return (0);
}
