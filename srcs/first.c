/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:27:04 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/23 15:28:55by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
	return (1);
}

void	init_mlx(t_data *set)
{
	set->mlx = mlx_init();
	set->mlx_win = mlx_new_window(set->mlx, 400, 400, set->type);
	set->img = mlx_new_image(set->mlx, 400, 400);
	set->addr = mlx_get_data_addr(set->img, &set->bits_per_pixel, &set->line_length, &set->endian);
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	else if (keycode == 65362)
		vars->y_cadre += 100 * vars->y_cadre/vars->zoom; 
	else if (keycode == 65364)
		vars->y_cadre -= 100 * vars->y_cadre/vars->zoom; 
	else if (keycode == 65363)
		vars->x_cadre -= 50 * vars->x_cadre/vars->zoom; 
	else if (keycode == 65361)
		vars->x_cadre += 50 * vars->x_cadre/vars->zoom; 
	ft_calc(vars);
	return (1);
}

int	mouse_hook(int mousecode, t_data *set)
{
	if (mousecode == 5)
		printf("yo\n");
	else if (mousecode == 4)
		printf("man\n");
	return (0);
}

int	first(t_data *set)
{
	mandelbrot_init(set);
	init_mlx(set);
	
	mlx_hook(set->mlx_win, 17, 1L<<2, ft_close, set);
	mlx_key_hook(set->mlx_win, key_hook, set);
	mlx_mouse_hook(set->mlx_win, mouse_hook, set);
	ft_calc(set);
	mlx_loop(set->mlx);
	
	return (1);
}