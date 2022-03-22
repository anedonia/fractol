/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:27:04 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/22 18:44:17 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	first(t_data *set)
{
	set->mlx = mlx_init();
	
	set->mlx_win = mlx_new_window(set->mlx, 1000, 800, set->type);
	set->img = mlx_new_image(set->mlx, 1000, 800);
	set->addr = mlx_get_data_addr(set->img, &set->bits_per_pixel, &set->line_length, &set->endian);
	ft_calc(set);
	//my_mlx_pixel_put(set, 0, 40, 0xffffffff);
	//mlx_put_image_to_window(set->mlx, set->mlx_win, set->img, 0, 0);
	//hook
	//hook de fermeture
	mlx_loop(set->mlx);
	
	return (1);
}