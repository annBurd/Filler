/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/19 19:26:33 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static void	usage(void)
{
	ft_printf("Usage: "
	"./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]\n\n"
	"\t-t  --time\t\tset timeout in second\n"
	"\t-q  --quiet\t\tquiet mode\n"
	"\t-i  --interactive\tinteractive mode(default)\n"
	"\t-p1 --player1\tuse filler binary as a first player\n"
	"\t-p2 --player2\tuse filler binary as a second player\n"
	"\t-f  --file\t\tuse a map file (required)\n"
	"\t-s  --seed\t\tuse the seed number (initialization random) (man srand)"
	"\n");
}

/*
** error:
** can not read the file// -1
** wrong map file // -2
** bad player
*/

int		fillit_exit(int code, void *p)
{
	if (code < 0)
	{
		perror("error:\n");
		p && ft_arraystrfree(p);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static void	handle_flags(t_filler *main, char **arg)
{
	int i;

	i = 0;
	main->p1 = NULL;
	main->p2 = NULL;
	while (arg[i] && arg[i][0] == '-')
	{
		if (ft_strequ(arg[i], "-t"))
			main->time = (size_t)ft_atoi(arg[++i]);
		else if (ft_strequ(arg[i], "-q"))
			main->q = 1;
		else if (ft_strequ(arg[i], "-i")) //(default)
			main->i = 1;
		else if (ft_strequ(arg[i], "-p1"))
			main->p1 = arg[++i];
		else if (ft_strequ(arg[i], "-p2"))
			main->p2 = arg[++i];
		else if (ft_strequ(arg[i], "-f")) //(required)
			get_board(&main->b, arg[++i]);
		else if (ft_strequ(arg[i], "-s"))
			main->s = 123; //here must be random (man srand)
//		else
			//error for unexist flag?
			i++;
	}
}

int	main(int argc, char **argv)
{
	t_filler	main;

	argc == 1 ? usage() : handle_flags(&main, ++argv);

	ft_printf(RED"Filler's end\n"RESET);
	return (0);
}