/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:14 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 16:36:18 by cle-tron         ###   ########.fr       */
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

void	fill_rgb(char *color, int *rgb)
{
	char	**rgb_array;
	int		i;

	rgb_array = ft_split(color, ',');
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(rgb_array[i]);
		free(rgb_array[i++]);
	}
	free(rgb_array);
}

void	init_ambient(char **elem, t_data *data)
{
	data->amb = malloc(sizeof(t_amb));
	data->amb->id = ft_strdup(elem[0]);
	data->amb->ratio = ft_atod(elem[1]);
	fill_rgb(elem[2], data->amb->rgb);
}

void	init(char *file, t_data *data)
{
	char **line;
	char **elem;
	char **tmp;

	(void)data;
	line = copy_elements(file);

	int i = 0;
	while(line[i])
	{
		elem = ft_split(line[i], ' ');
		tmp = elem;
		if (element_id(tmp[0]) == AMBIENT)
			init_ambient(elem, data);
			//printf("%s", line[i]);
		while(*tmp)
		{
			printf("%s\n", *tmp);
			free(*tmp);
			tmp++;
		}
		free(elem);
		free(line[i++]);

	}
	free(line);
}
