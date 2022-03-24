/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:54:15 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/23 16:32:23 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//void une ft qui choisie le type de set 

void ft_calc(t_data *set)
{
	set->x = 0;
	while (set->x < WIDTH)
	{
		set->y = 0;
		while (set->y < WIDTH)
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
	set->x_cadre = -1;
	set->y_cadre = -1;
	set->ite_max = 50;
	set->c_r = 0.285;
	set->c_i = 0.01;
	set->zoom = WIDTH/3.8;
}
// void	mandelbrot_init(t_data *set)
// {
// 	set->x_cadre = -2;
// 	set->y_cadre = -0.99;
// 	set->ite_max = 70;
// 	set->zoom = WIDTH/2;
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_color_int(float ite)
{
	float r;
	float g;
	float b;
	
	r = 255 * ((1 - cos(ite / log(2))) / 2);
	g = 255 * ((1 - cos(ite * (1 / ((3 * sqrt(2)) / log(2))))) / 2);
	b = 255 * ((1 - cos(ite * (1 / ((7 * pow(3, 1/8)) / log(2))))) / 2);
	return (create_trgb(0, r, g, b));
}

int	ft_mandelbrot(t_data *set)
{
	set->z_r = set->x / set->zoom + set->x_cadre;
	set->z_i = set->y / set->zoom + set->y_cadre;
	//printf ("\ncr : %Lf ci : %Lf ", set->c_r, set->c_i);
	set->ite = 0;
	while (set->z_r * set->z_r + set->z_i * set->z_i < 4 && set->ite < set->ite_max)
	{
		set->temp = set->z_r;
		set->z_r = set->z_r * set->z_r - set->z_i * set->z_i + set->c_r;
		set->z_i = 2 * set->temp * set->z_i + set->c_i;
		set->ite++;
	}
	//printf("\n%d, %d yo",set->x, set->y);
	if (set->ite == set->ite_max)
		my_mlx_pixel_put(set, set->x, set->y, 0x00000000);
	else 
		my_mlx_pixel_put(set, set->x, set->y,ft_color_int(set->ite));
	//printf(" x^2 + y^2: %f, ite : %d\n",x*x + y*y, set->ite);

	return (1);
}

// int	ft_mandelbrot(t_data *set)
// {
	
// 	float x;
// 	float y;
	
// 	x = 0;
// 	y = 0;
// 	set->c_r = (long double)set->x / set->zoom + set->x_cadre;
// 	set->c_i = (long double)set->y / set->zoom + set->y_cadre;
// 	//printf ("\ncr : %Lf ci : %Lf ", set->c_r, set->c_i);
// 	set->ite = 0;
// 	set->z_r = 0;
// 	set->z_i = 0;
// 	set->temp = 0;
// 	while (x*x + y*y <= 4 && set->ite < set->ite_max)
// 	{
// 		set->temp = x*x - y*y + set->c_r;
// 		y = 2*x*y + set->c_i;
// 		x = set->temp;
// 		set->ite++;
// 	}
// 	//printf("\n%d, %d yo",set->x, set->y);
// 	if (set->ite == set->ite_max)
// 		my_mlx_pixel_put(set, set->x, set->y, 0x00000000);
// 	else 
// 		my_mlx_pixel_put(set, set->x, set->y, ft_color_int(set->ite));
// 	//printf(" x^2 + y^2: %f, ite : %d\n",x*x + y*y, set->ite);

// 	return (1);
// }

//burbing ship
// int	ft_mandelbrot(t_data *set)
// {
	
// 	float x;
// 	float y;
	
// 	x = 0;
// 	y = 0;
// 	set->c_r = (long double)set->x / set->zoom + set->x_cadre;
// 	set->c_i = (long double)set->y / set->zoom + set->y_cadre;
// 	//printf ("\ncr : %Lf ci : %Lf ", set->c_r, set->c_i);
// 	set->ite = 0;
// 	set->z_r = 0;
// 	set->z_i = 0;
// 	set->temp = 0;
// 	while (x*x + y*y <= 4 && set->ite < set->ite_max)
// 	{
// 		set->temp = x*x - y*y + set->c_r;
// 		y = fabs(2*x*y) + set->c_i;
// 		x = set->temp;
// 		set->ite++;
// 	}
// 	//printf("\n%d, %d yo",set->x, set->y);
// 	if (set->ite == set->ite_max)
// 		my_mlx_pixel_put(set, set->x, set->y, 0x00000000);
// 	else 
// 		my_mlx_pixel_put(set, set->x, set->y, ft_color_int(set->ite));
// 	//printf(" x^2 + y^2: %f, ite : %d\n",x*x + y*y, set->ite);

// 	return (1);
// }