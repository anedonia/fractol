/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:33:48 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/28 14:12:38 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# define WIDTH 400

typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	char		*type;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			ite_max;
	int			ite;
	int			x;
	int			y;
	int			ntype;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	x_cadre;
	long double	y_cadre;
	long double	temp;
	long double	zoom;
}	t_data;

//hooks
int		ft_close(t_data *data);
int		key_hook(int keycode, t_data *vars);
void	ft_zoom(int x, int y, t_data *set);
void	ft_dezoom(int x, int y, t_data *set);
int		mouse_hook(int mousecode, int x, int y, t_data *set);

//tools
int		create_trgb(int t, int r, int g, int b);
int		ft_color_int(float ite);
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		ft_atoi(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);

//fractals
void	ft_calc_burningship(t_data *set);
void	burningship_init(t_data *set);
int		ft_burningship(t_data *set);
void	ft_calc_julia(t_data *set);
void	julia_init(t_data *set, char **argv, int argc);
int		ft_julia(t_data *set);
void	ft_calc_mandelbrot(t_data *set);
void	mandelbrot_init(t_data *set);
int		ft_mandelbrot(t_data *set);

//first
void	init_mlx(t_data *set);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	choose_calc(t_data *set);
int		first(t_data *set);

//main
void	fractal_selector(t_data *set, char **argv, int argc);
void	fractal_init(t_data *set, char **argv, int argc);
void	print_error(void);

#endif