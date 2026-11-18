/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+  +:+       +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/21 20:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
