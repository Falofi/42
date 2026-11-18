/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+  +:+       +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/21 20:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	concatenate(char *c, char const *s1, char const *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		c[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		c[k] = s2[i];
		i++;
		k++;
	}
	c[k] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		lenall;

	if (!s1 || !s2)
		return (NULL);
	lenall = ft_strlen(s1) + ft_strlen(s2);
	c = malloc(sizeof(char) * (lenall + 1));
	if (c == NULL)
		return (NULL);
	concatenate(c, s1, s2);
	return (c);
}
