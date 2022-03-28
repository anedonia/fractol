/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:36:54 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/28 14:06:56 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_calc_julia(t_data *set)
{
	set->x = 0;
	while (set->x < WIDTH)
	{
		set->y = 0;
		while (set->y < WIDTH)
		{
			ft_julia(set);
			set->y++;
		}
		set->x++;
	}
	mlx_put_image_to_window(set->mlx, set->mlx_win, set->img, 0, 0);
}

void	julia_init(t_data *set, char **argv, int argc)
{
	set->x_cadre = -1;
	set->y_cadre = -1;
	set->ite_max = 50;
	if (argc == 2)
	{
		set->c_r = 0.285;
		set->c_i = 0.01;
	}
	else if (ft_atoi(argv[2]) != 0 && ft_atoi(argv[3]) != 0)
	{
		set->c_r = 2 / ft_atoi(argv[2]);
		set->c_i = 2 / ft_atoi(argv[3]);
	}
	else
		print_error();
	set->zoom = WIDTH / 3.8;
	set->type = "julia";
}

int	ft_julia(t_data *set)
{
	set->z_r = set->x / set->zoom + set->x_cadre;
	set->z_i = set->y / set->zoom + set->y_cadre;
	set->ite = 0;
	while (set->z_r * set->z_r + set->z_i * set->z_i < 4
		&& set->ite < set->ite_max)
	{
		set->temp = set->z_r;
		set->z_r = set->z_r * set->z_r - set->z_i * set->z_i + set->c_r;
		set->z_i = 2 * set->temp * set->z_i + set->c_i;
		set->ite++;
	}
	if (set->ite == set->ite_max)
		my_mlx_pixel_put(set, set->x, set->y, 0x00000000);
	else
		my_mlx_pixel_put(set, set->x, set->y, ft_color_int(set->ite));
	return (1);
}
