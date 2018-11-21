/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:48:54 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/21 20:09:35 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_f			f;

static void	show_usage(void)
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
	exit(EXIT_FAILURE);
}

/*
** error:
** can not read the file// -1
** wrong map file // -2
** bad player
*/

int			f_exit(int code)
{
//	if (code < 0)
		perror("error:\n");
	//free memory depending on code
	if (f.board)
		ft_arraystrfree(f.board);
	exit(code);
}

static void	handle_flags(char **arg)
{
	srand((unsigned)time(0));
	ft_bzero(&f, sizeof(t_f));
	while (*arg)
	{
		if (ft_strequ(*arg, "-t"))
			f.time = (size_t)ft_atoi(*(++arg));
		else if (ft_strequ(*arg, "-q"))
			f.quietMode = 1;
		else if (ft_strequ(*arg, "-i")) //(default)
			f.interactiveMode = 1;
		else if (ft_strequ(*arg, "-p1"))
			f.p1 = *(++arg);
		else if (ft_strequ(*arg, "-p2"))
			f.p2 = *(++arg);
		else if (ft_strequ(*arg, "-f")) //(required)
			get_board(*(++arg));
		else if (ft_strequ(*arg, "-s"))
			f.seed = (size_t)rand();
		else
			break ;//error for unexist flag? ignor?
		arg++;
	}
	print_board();// del me
}

int			main(int argc, char **argv)
{
	argc == 1 ? show_usage() : handle_flags(++argv);
	start_game();
	ft_printf(RED"Filler's end\n"RESET);
	ft_arraystrfree(f.board);
	return (0);
}