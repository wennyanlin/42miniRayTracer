/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:40:06 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/08 18:41:10 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/get_next_line.h"

char	*read_line(int fd, char *stash)
{
	int		read_bytes;
	char	*buf;

	buf = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buf[read_bytes] = '\0';
			stash = ft_strjoin(stash, buf);
			if (!stash)
				return (free(buf), NULL);
		}
	}
	if (read_bytes == -1)
		return (free(stash), free(buf), NULL);
	return (free(buf), stash);
}

char	*extract_line(char *stash)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	result = ft_substr(stash, 0, i + 1);
	if (!result)
		return (NULL);
	return (result);
}

char	*extract_stash(char *stash)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!stash[0])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	result = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!result)
		return (free(stash), NULL);
	return (free(stash), result);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (free(stash), NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = extract_stash(stash);
	return (line);
}
