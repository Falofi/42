/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+  +:+       +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/21 20:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	n;

	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (i < len && str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			n = 0;
			while (i + n < len && str[i + n] == to_find[n]
				&& to_find[n] != '\0')
				n++;
			if (to_find[n] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
