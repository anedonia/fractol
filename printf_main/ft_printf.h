/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:17:07 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/20 21:42:21 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	to_hex(unsigned long nb, int up, int p, int *res);
int		ft_putchar(int c);
void	ft_putstr(char *s, int *res);
void	ft_putnbr(int nb, int *res);
void	ft_putnbr_u(int nb, int *res);
int		ft_switch(va_list ap, char c);
#endif