/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:14 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/13 17:42:23 by cle-tron         ###   ########.fr       */
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
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

char	**copy_elements(char *file)
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

void	init(char *file, t_data *data)
{
	char	**line;
	char	**elem;

	data->obj = NULL;
	line = copy_elements(file);
	int i = 0;
	while(line[i])
	{
		printf("%s", line[i]);
		elem = ft_split(line[i], ' ');
		if (element_id(elem[0]) == AMBIENT)
			init_ambient(elem, data);
		else if (element_id(elem[0]) == CAMERA)
			init_camera(elem, data);
		else if (element_id(elem[0]) == LIGHT)
			init_light(elem, data);
		else if (element_id(elem[0]) >= SPHERE)
			init_objects(elem, &data->obj);
		free_array(elem);
		free(line[i++]);
	}
	free(line);
}
