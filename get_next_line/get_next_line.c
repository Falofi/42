/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomperei <tomperei@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 04:05:00 by tomperei          #+#    #+#             */
/*   Updated: 2026/11/19 05:41:39 by tomperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*free_both(char *a, char *b)
{
	free(a);
	free(b);
	return (NULL);
}

static char	*read_to_stash(int fd, char *stash)
{
	char		*buf;
	int			bytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free_both(buf, stash));
	bytes = 1;
	while (bytes != 0 && bytes != -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free_both(buf, stash));
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free_both(buf, stash));
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;
	char		*nl;

	stash = read_to_stash(fd, stash);
	if (!stash || !stash[0])
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	nl = ft_strchr(stash, '\n');
	if (!nl)
	{
		line = stash;
		stash = NULL;
		return (line);
	}
	line = ft_substr(stash, 0, nl - stash + 1);
	tmp = stash;
	stash = ft_substr(stash, nl - tmp + 1, ft_strlen(tmp));
	free(tmp);
	return (line);
}
