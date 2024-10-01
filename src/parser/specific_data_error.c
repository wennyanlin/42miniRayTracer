/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_data_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:16:52 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/28 15:35:39 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	light_error(char **elem)
{
	if (array_len(elem) != 3)
		return (ft_putendl_fd(\
			"Error: Light needs 2 parameters: coordinates and ratio", 2), 1);
	if (check_xyz(elem[1], elem[0], "coordinate"))
		return (1);
	if (check_ratio(elem[2], elem[0]))
		return (1);
	return (0);
}

int	camera_error(char **elem)
{
	if (array_len(elem) != 4)
		return (ft_putendl_fd(\
		"Error: Camera needs 3 parameters: coordinates, vectors, fov", 2), 1);
	if (check_xyz(elem[1], elem[0], "coordinate"))
		return (1);
	if (check_xyz(elem[2], elem[0], "vector"))
		return (1);
	if (int_syntax(elem[3]))
		return (print_syntax_error(elem[3], "fov", "integer", elem[0]), 1);
	if (ft_strlen(elem[3]) > 9 || ft_atoi(elem[3]) < 0 || \
														ft_atoi(elem[3]) > 180)
		return (print_range_error(elem[3], "fov", elem[0], "0,180"), 1);
	return (0);
}

int	ambient_error(char **elem)
{
	if (array_len(elem) != 3)
		return (ft_putendl_fd(\
				"Error: Ambient needs two parameters: ratio and rgb", 2), 1);
	if (check_ratio(elem[1], elem[0]))
		return (1);
	if (check_rgb(elem[2], elem[0]))
		return (1);
	return (0);
}

int	check_specific_data(char **line)
{
	char	**elem;
	int		i;

	i = 0;
	while (line[i])
	{
		elem = ft_split(line[i], ' ');
		if (element_id(elem[0]) == AMBIENT && ambient_error(elem))
			return (free_array(elem), 1);
		else if (element_id(elem[0]) == CAMERA && camera_error(elem))
			return (free_array(elem), 1);
		else if (element_id(elem[0]) == LIGHT && light_error(elem))
			return (free_array(elem), 1);
		else if (element_id(elem[0]) == SPHERE && sphere_error(elem))
			return (free_array(elem), 1);
		else if (element_id(elem[0]) == PLANE && plane_error(elem))
			return (free_array(elem), 1);
		else if (element_id(elem[0]) == CYLINDER && cylinder_error(elem))
			return (free_array(elem), 1);
		free_array(elem);
		i++;
	}
	return (0);
}
