/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                  +#+  +:+       +#+        */
/*   By: tomperei <tomperei@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                  +#+  +:+       +#+        */
/*   Created: 2026/10/21 20:30:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/10/21 20:30:00 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_word(char const *str, char charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		if (str[i] != '\0' && str[i] != charset)
		{
			j++;
			while (str[i] != '\0' && str[i] != charset)
				i++;
		}
	}
	return (j);
}

static char	*ft_copy(char const *str, int i, int j)
{
	char	*word;
	int		m;

	word = malloc(sizeof(char) * (j + 1));
	if (!word)
		return (NULL);
	m = 0;
	while (m < j)
	{
		word[m] = str[i - j + m];
		m++;
	}
	word[m] = '\0';
	return (word);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	fill_tab(char **tab, char const *str, char charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == charset)
			i++;
		j = i;
		while (str[i] != '\0' && str[i] != charset)
			i++;
		if (i > j)
		{
			tab[k] = ft_copy(str, i, i - j);
			if (!tab[k])
				return (0);
			k++;
		}
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, s, c))
	{
		free_tab(tab);
		return (NULL);
	}
	return (tab);
}
