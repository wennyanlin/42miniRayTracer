/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:14 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/04 19:04:21 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		count_lines(char *file)
{
	int		fd;
	int		i;
	char	*line;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (errno);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!ft_strncmp(line, "\n", 1))
		{
			free(line);
			continue;
		}
//		printf("%s", line);
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

char	**copy_data(char *file)
{
	int		fd;
	int		i;
	int		count;
	char	*line;
	char	**data;
	
	count = count_lines(file);
	data = malloc(sizeof(char *) * (count + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (errno);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!ft_strncmp(line, "\n", 2))
		{
			free(line);
			continue;
		}
		data[i++] = line;
	}
	close(fd);
	data[i] = NULL;
	return (data);
}

void	init(char *file)
{
	char **data;

	data = copy_data(file);
	int i = 0;
	while(data[i])
	{
		printf("%s", data[i]);
		free(data[i++]);
	}
	free(data);
}
