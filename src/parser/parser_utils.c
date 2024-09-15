/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:00:53 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/15 14:46:03 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	count_lines(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		system_error(file);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "\n", 1))
		{
			free(line);
			continue ;
		}
		i++;
		free(line);
	}
	close(fd);
	return (i);
}
/*
static int	reserve_malloc(char ***data, char *file, int fd)
{
	int	count;

	count = count_lines(file);
	if (count == 0) //EMPTYFILE
		return (1);
	*data = malloc(sizeof(char *) * (count + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1 || !data)
		system_error("malloc");
	return (0);
}
*/
char	**copy_elements(char *file)
{
	int		fd;
	int		count;
	int		i;
	char	*line;
	char	**data;

	count = count_lines(file);
	if (count == 0) //EMPTYFILE
		return (NULL);
	data = malloc(sizeof(char *) * (count + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1 || !data)
		system_error("malloc");

//	fd = -1;
//	if (reserve_malloc(&data, file, fd))
//		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line) //NOSE PUEDEQUITAR
			break ;
		if (line && !ft_strncmp(line, "\n", 2))
		{
			free(line);
			continue ;
		}
		data[i++] = line;
	}
	close(fd);
	data[i] = NULL; //NOSE PUEDEQUITAR
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
