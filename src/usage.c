/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:55:38 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/17 19:38:52 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	usage(void)
{
	ft_printf("Usage: "
"./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]\n\n"
"\t-t  --time\t\tset timeout in second\n"
"\t-q  --quiet\t\tquiet mode\n"
"\t-i  --interactive\tinteractive mode(default)\n"
"\t-p1 --player1\tuse filler binary as a first player\n"
"\t-p2 --player2\tuse filler binary as a second player\n"
"\t-f  --file\t\tuse a map file (required)\n"
"\t-s  --seed\t\tuse the seed number (initialization random) (man srand)\n");
}

void	handle_flags(t_filler *z, char **arg)
{
	int i;

	i = 0;
	F.p1 = NULL;
	F.p2 = NULL;
	F.file = NULL;
	while (arg[i] && arg[i][0] == '-')
	{
		if (ft_strequ(arg[i], "-t"))
			F.time = (size_t)ft_atoi(arg[++i]);
		else if (ft_strequ(arg[i], "-q"))
			F.q = 1;
		else if (ft_strequ(arg[i], "-i"))
			F.i = 1;
		else if (ft_strequ(arg[i], "-p1"))
			F.p1 = arg[++i];
		else if (ft_strequ(arg[i], "-p2"))
			F.p2 = arg[++i];
		else if (ft_strequ(arg[i], "-f"))
			F.file = arg[++i];
		else if (ft_strequ(arg[i], "-s"))
			F.s = 123; //here must be random (man srand)
		else
			//error
		i++;
	}
}
