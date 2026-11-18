/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+  +:+       +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/21 20:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*last;
	size_t	i;

	ch = (char)c;
	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			last = (char *)&s[i];
		i++;
	}
	if (ch == '\0')
		last = (char *)&s[i];
	return (last);
}
