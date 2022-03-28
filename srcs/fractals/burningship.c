/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:40:05 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/28 14:05:02 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_calc_burningship(t_data *set)
{
	set->x = 0;
	while (set->x < WIDTH)
	{
		set->y = 0;
		while (set->y < WIDTH)
		{
			ft_burningship(set);
			set->y++;
		}
		set->x++;
	}
	mlx_put_image_to_window(set->mlx, set->mlx_win, set->img, 0, 0);
}

void	burningship_init(t_data *set)
{
	set->x_cadre = -2;
	set->y_cadre = -1;
	set->ite_max = 70;
	set->zoom = WIDTH / 2;
	set->type = "burningship";
}

int	ft_burningship(t_data *set)
{
	float	x;
	float	y;

	x = 0;
	y = 0;
	set->c_r = (long double)set->x / set->zoom + set->x_cadre;
	set->c_i = (long double)set->y / set->zoom + set->y_cadre;
	set->ite = 0;
	set->z_r = 0;
	set->z_i = 0;
	set->temp = 0;
	while (x * x + y * y <= 4 && set->ite < set->ite_max)
	{
		set->temp = x * x - y * y + set->c_r;
		y = fabs(2 * x * y) + set->c_i;
		x = set->temp;
		set->ite++;
	}
	if (set->ite == set->ite_max)
		my_mlx_pixel_put(set, set->x, set->y, 0x00000000);
	else
		my_mlx_pixel_put(set, set->x, set->y, ft_color_int(set->ite));
	return (1);
}
