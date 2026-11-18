/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+  +:+       +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/21 20:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	length;
	char	*tab;
	size_t	i;

	length = ft_strlen(src);
	tab = malloc(sizeof(char) * (length + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < (length + 1))
	{
		tab[i] = src[i];
		i++;
	}
	return (tab);
}
