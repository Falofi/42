/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomperei <tomperei@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 04:05:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/11/18 08:20:21 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_convert(char c, va_list *args)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putbase(va_arg(*args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putbase(va_arg(*args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putbase(va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	return (0);
}

static int	ft_parse(const char *format, va_list *args)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (format[i])
	{
		ret = 0;
		if (format[i] == '%' && format[i + 1])
		{
			ret = ft_convert(format[i + 1], args);
			i++;
		}
		else if (format[i] != '%')
			ret = ft_putchar(format[i]);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_parse(format, &args);
	va_end(args);
	return (count);
}
