/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomperei <tomperei@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 04:05:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/11/18 08:17:42 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr(int n)
{
	char	*str;
	int		ret;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	ret = write(1, str, ft_strlen(str));
	free(str);
	return (ret);
}

int	ft_putbase(unsigned long n, char *base)
{
	unsigned long	len;
	int				i;
	int				ret;

	len = ft_strlen(base);
	i = 0;
	if (n >= len)
	{
		i += ft_putbase(n / len, base);
		if (i == -1)
			return (-1);
	}
	ret = ft_putchar(base[n % len]);
	if (ret == -1)
		return (-1);
	return (ret + i);
}

int	ft_putptr(void *n)
{
	int	ret;
	int	ret2;

	ret2 = 0;
	if (!n)
	{
		ret = write(1, "(nil)", 5);
		if (ret == -1)
			return (-1);
	}
	else
	{
		ret = write(1, "0x", 2);
		if (ret == -1)
			return (-1);
		ret2 = ft_putbase((unsigned long)n, "0123456789abcdef");
		if (ret2 == -1)
			return (-1);
	}
	return (ret + ret2);
}
