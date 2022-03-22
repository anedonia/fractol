/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:42:26 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/22 15:56:47 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data set;
	
	// if (argc == 1 || (argv[1] && argv[1][0] != 'm'))
	// 	return (0);
	// set.type = argv[1][0];
	set.type = "madelbrot";
	first(&set);
}