/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:42:26 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/28 14:04:04 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fractal_selector(t_data *set, char **argv, int argc)
{
	if (!ft_strcmp("mandelbrot", argv[1]) && argc == 2)
		set->ntype = 0;
	else if (!ft_strcmp("burningship", argv[1]) && argc == 2)
		set->ntype = 1;
	else if (!ft_strcmp("julia", argv[1]))
		set->ntype = 2;
	else
		print_error();
}

void	fractal_init(t_data *set, char **argv, int argc)
{
	if (set->ntype == 0)
		mandelbrot_init(set);
	else if (set->ntype == 1)
		burningship_init(set);
	else if (set->ntype == 2)
		julia_init(set, argv, argc);
	else
		exit(0);
}

void	print_error(void)
{
	ft_printf("fractol \"mandelbrot\" or \"julia\"");
	ft_printf("or \"burningship\" are possible arguments\n");
	ft_printf("if julia set is selected you may input");
	ft_printf("two more args ex : \"12\" \"58\" with \"0\" excluded (numbers)\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	set;

	if (argc == 2 || argc == 4)
		fractal_selector(&set, argv, argc);
	else
		print_error();
	fractal_init(&set, argv, argc);
	first(&set);
}
