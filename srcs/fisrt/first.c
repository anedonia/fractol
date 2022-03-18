/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:27:04 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/18 14:45:39 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	game(t_data *set)
{
	set->mlx = mlx_init();
	
	set->mlx_win = mlx_new_window(set->mlx,400, 400, set->type);
	ft_calc(set);
	//hook
	//hook de fermeture
	mlx_loop(set->mlx);
	
	return (1);
}