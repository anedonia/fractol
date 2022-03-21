/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:54:15 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/21 22:06:20 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

//void une ft qui choisie le type de set 

void ft_calc(t_data *set)
{
	int i;
	int j;

	i = 0;
	while (set->x = i < 400)
	{
		j = 0;
		while (set->y = j < 400)
		{
			ft_mandelbrot(&set);
			j++;
		}
		i++;
	}
}

void	mandelbrot_init(t_data *set)
{
	set->x_cadre = -2;
	set->y_cadre = -2;
	set->ite_max = 50;
	set->zoom = 200;
}

int	ft_mandelbrot(t_data *set)
{
	set->		
}