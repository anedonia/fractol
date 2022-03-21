/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:33:48 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/21 22:00:20 by ldevy            ###   ########.fr       */
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
# include <math.h>

typedef	struct s_data
{
	void *img;
	void *mlx;
	void *mlx_win;
	char *addr;
	int type;
	int bits_per_pixel;
	int line_length;
	int endian;
	int ite_max;
	int x;
	int y;
	float c_r;
	float c_i;
	float x_cadre;
	float y_cadre;
	int zoom;
	
	
	
}	t_data;


#endif