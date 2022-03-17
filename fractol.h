/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:33:48 by ldevy             #+#    #+#             */
/*   Updated: 2022/03/16 15:09:05 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct s_data
{
	void *img;
	void *mlx;
	void *mlx_win;
	char type;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;

//printf : 

int		ft_printf(const char *str, ...);
void	to_hex(unsigned long nb, int up, int p, int *res);
int		ft_putchar(int c);
void	ft_putstr(char *s, int *res);
void	ft_putnbr(int nb, int *res);
void	ft_putnbr_u(int nb, int *res);
int		ft_switch(va_list ap, char c);

#endif