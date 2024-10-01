/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:21:40 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/28 16:06:52 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sphere_error(char **elem)
{
	if (array_len(elem) != 4)
		return (ft_putendl_fd(\
	"Error: Sphere needs 3 parameters: coordinates, diameter, color", 2), 1);
	if (check_xyz(elem[1], elem[0], "coordinate"))
		return (1);
	if (check_measure(elem[2], elem[0], "diameter"))
		return (1);
	if (check_rgb(elem[3], elem[0]))
		return (1);
	return (0);
}

int	plane_error(char **elem)
{
	if (array_len(elem) != 4)
		return (ft_putendl_fd(\
		"Error: Plane needs 3 parameters: coordinates, vectors, color", 2), 1);
	if (check_xyz(elem[1], elem[0], "coordinate"))
		return (1);
	if (check_xyz(elem[2], elem[0], "vector"))
		return (1);
	if (check_rgb(elem[3], elem[0]))
		return (1);
	return (0);
}

int	cylinder_error(char **elem)
{
	if (array_len(elem) != 6)
		return (ft_putendl_fd(\
	"Error: Plane needs 5 parameters: coordinates, vectors, diameter, height, \
color", 2), 1);
	if (check_xyz(elem[1], elem[0], "coordinate"))
		return (1);
	if (check_xyz(elem[2], elem[0], "vector"))
		return (1);
	if (check_measure(elem[3], elem[0], "diameter"))
		return (1);
	if (check_measure(elem[4], elem[0], "height"))
		return (1);
	if (check_rgb(elem[5], elem[0]))
		return (1);
	return (0);
}
