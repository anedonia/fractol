/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:41:41 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/25 16:59:19 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
	return (1);
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 65307)
		ft_close(vars);
	else if (keycode == 65362)
		vars->y_cadre -= 10 / vars->zoom; 
	else if (keycode == 65364)
		vars->y_cadre += 10 / vars->zoom; 
	else if (keycode == 65363)
		vars->x_cadre += 10 / vars->zoom; 
	else if (keycode == 65361)
		vars->x_cadre -= 10 / vars->zoom; 
	choose_calc(vars);
	return (1);
}

void	ft_zoom(int x, int y, t_data *set)
{
	set->y_cadre = (y / set->zoom + set->y_cadre) - (y / (set->zoom * 1.1));
	set->x_cadre = (x / set->zoom + set->x_cadre) - (x / (set->zoom * 1.1)); 
	set->zoom *= 1.1;
	set->ite_max++;
}

void	ft_dezoom(int x, int y, t_data *set)
{

	set->y_cadre = (y / set->zoom + set->y_cadre) - (y / (set->zoom / 1.1));
	set->x_cadre = (x / set->zoom + set->x_cadre) - (x / (set->zoom / 1.1)); 
	set->zoom /= 1.1;
	set->ite_max--;
}

int	mouse_hook(int mousecode, int x, int y, t_data *set)
{
	if (mousecode == 5)
		ft_zoom(x, y, set);
	else if (mousecode == 4)
		ft_dezoom(x, y, set);
	choose_calc(set);
	return (0);
}