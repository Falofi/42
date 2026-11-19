/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomperei <tomperei@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 04:05:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/11/19 05:49:35 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

static void	concatenate(char *c, char const *s1, char const *s2)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			c[k] = s1[i];
			i++;
			k++;
		}
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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*c;
	int		lenall;

	if (!s2)
		return (NULL);
	if (!s1)
		lenall = ft_strlen(s2);
	else
		lenall = ft_strlen(s1) + ft_strlen(s2);
	c = malloc(sizeof(char) * (lenall + 1));
	if (c == NULL)
	{
		free(s1);
		return (NULL);
	}
	concatenate(c, s1, s2);
	free(s1);
	return (c);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
