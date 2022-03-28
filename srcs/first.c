/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:55:53 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/28 14:02:16 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mlx(t_data *set)
{
	set->mlx = mlx_init();
	set->mlx_win = mlx_new_window(set->mlx, WIDTH, WIDTH, set->type);
	set->img = mlx_new_image(set->mlx, WIDTH, WIDTH);
	set->addr = mlx_get_data_addr(set->img, &set->bits_per_pixel,
			&set->line_length, &set->endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 7));
	*(unsigned int *) dst = color;
}

void	choose_calc(t_data *set)
{
	if (set->ntype == 0)
		ft_calc_mandelbrot(set);
	if (set->ntype == 1)
		ft_calc_burningship(set);
	if (set->ntype == 2)
		ft_calc_julia(set);
}

int	first(t_data *set)
{
	init_mlx(set);
	mlx_hook(set->mlx_win, 17, 1L << 2, ft_close, set);
	mlx_key_hook(set->mlx_win, key_hook, set);
	mlx_mouse_hook(set->mlx_win, mouse_hook, set);
	choose_calc(set);
	mlx_loop(set->mlx);
	return (1);
}
