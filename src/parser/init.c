/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:14 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 17:48:40 by cle-tron         ###   ########.fr       */
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

int	element_id(char *elem)
{
	if (!ft_strncmp(elem, "A", 2))
		return (AMBIENT);
	else if (!ft_strncmp(elem, "C", 2))
		return (CAMERA);
	else if (!ft_strncmp(elem, "L", 2))
		return (LIGHT);
	else if (!ft_strncmp(elem, "sp", 3))
		return (SPHERE);
	else if (!ft_strncmp(elem, "pl", 3))
		return (PLANE);
	else if (!ft_strncmp(elem, "cy", 3))
		return (CYLINDER);
	else
		return (-1);
}

void	init(char *file, t_data *data)
{
	char **line;
	char **elem;

	(void)data;
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
		free_array(elem);
		free(line[i++]);

	}
	free(line);
}
