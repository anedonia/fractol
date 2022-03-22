/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:54:15 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/22 18:45:42 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//void une ft qui choisie le type de set 

void ft_calc(t_data *set)
{
	set->x = 0;
	mandelbrot_init(set);
	while (set->x < 1000)
	{
		set->y = 0;
		while (set->y < 800)
		{
			ft_mandelbrot(set);
			set->y++;
		}
		set->x++;
	}
	mlx_put_image_to_window(set->mlx, set->mlx_win, set->img, 0, 0);
}

void	mandelbrot_init(t_data *set)
{
	set->x_cadre = -4;
	set->y_cadre = -2;
	set->ite_max = 400;
	set->zoom = 200;
}

int	ft_mandelbrot(t_data *set)
{
	
	float x;
	float y;
	
	x = 0;
	y = 0;
	set->c_r = (float)set->x / (float)set->zoom + set->x_cadre;
	set->c_i = (float)set->y / (float)set->zoom + set->y_cadre;
	printf ("\ncr : %f ci : %f ", set->c_r, set->c_i);
	set->ite = 0;
	set->z_r = 0;
	set->z_i = 0;
	set->temp = 0;
	while (x*x + y*y <= 4 && set->ite < set->ite_max)
	{
		set->temp = x*x - y*y + set->c_r;
		y = 2*x*y + set->c_i;
		x = set->temp;
		set->ite++;
	}
	//printf("\n%d, %d yo",set->x, set->y);
	if (set->ite == set->ite_max)
		my_mlx_pixel_put(set, set->x, set->y, 0xffffffff);
	else 
		my_mlx_pixel_put(set, set->x, set->y, 0X00000000);
	//printf(" x^2 + y^2: %f, ite : %d\n",x*x + y*y, set->ite);

	return (1);
}