/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:33:48 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/22 18:34:15 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL
# include "mlx/mlx.h"
# include "libft_main/libft.h"
# include "printf_main/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <math.h>

typedef	struct s_data
{
	void *img;
	void *mlx;
	void *mlx_win;
	char *addr;
	char *type;
	int bits_per_pixel;
	int line_length;
	int endian;
	int ite_max;
	int ite;
	int x;
	int y;
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	float x_cadre;
	float y_cadre;
	float temp;
	int zoom;
	
	
	
}	t_data;
void	mandelbrot_init(t_data *set);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	ft_mandelbrot(t_data *set);
void ft_calc(t_data *set);
int	first(t_data *set);
#endif