/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/26 17:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_nbrlen(unsigned int nb, int neg)
{
	size_t	len;

	len = 1;
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len + (size_t)neg);
}

static void	ft_put_digits(char *str, unsigned int nb, size_t end)
{
	while (nb > 0)
	{
		end--;
		str[end] = (char)(nb % 10) + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	size_t			len;
	int				neg;

	neg = (n < 0);
	if (neg)
		nb = -(unsigned int)n;
	else
		nb = (unsigned int)n;
	len = ft_nbrlen(nb, neg);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (neg)
		str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	ft_put_digits(str, nb, len);
	return (str);
}
