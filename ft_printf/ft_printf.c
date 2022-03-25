/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:36:48 by ldevy             #+#    #+#             */
/*   Updated: 2021/12/20 21:37:48 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(va_list ap, char c)
{
	int	res;

	res = 0;
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), &res);
	if (c == 'u')
		ft_putnbr_u(va_arg(ap, int), &res);
	if (c == 'c')
		res = ft_putchar(va_arg(ap, int));
	if (c == 's')
		ft_putstr(va_arg(ap, char *), &res);
	if (c == 'x')
		to_hex(va_arg(ap, int), 0, 0, &res);
	if (c == 'X')
		to_hex(va_arg(ap, int), 1, 0, &res);
	if (c == 'p')
		to_hex(va_arg(ap, unsigned long), 0, 1, &res);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	size;
	size_t	i;

	va_start(ptr, str);
	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && str[i + 1] != '%')
		{
			size += ft_switch(ptr, str[i + 1]);
			i += 2;
		}
		else if (str[i] == '%' && str[i + 1] && str[i + 1] == '%')
		{
			size += ft_putchar(str[i]);
			i += 2;
		}
		else
			size += ft_putchar(str[i++]);
	}
	va_end(ptr);
	return (size);
}
