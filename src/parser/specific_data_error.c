/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_data_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:16:52 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/26 18:46:42 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


int	double_syntax(char *arg)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if ((arg[i] && arg[i] == '+') || (arg[i] && arg[i] == '-'))
		i++;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			point++;
			i++;
			if (point > 1)
				return (1);
		}
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	if (!ft_isdigit(arg[i - 1]))
		return (1);
	return (0);
}


int	check_ratio(char *ratio, char *id)
{
	if (double_syntax(ratio))
	{
		ft_putstr_fd("Error: \"", 2);
		ft_putstr_fd(ratio, 2);
		ft_putstr_fd("\" the syntax for the ratio value in the ", 2);
		ft_putstr_fd(id, 2);
		ft_putendl_fd(" parameter is incorrect", 2);
		return (1);
	}
	if (ft_atod(ratio) < 0 || ft_atod(ratio) > 1)
	{
		ft_putstr_fd("Error: \"", 2);
		ft_putstr_fd(ratio, 2);
		ft_putstr_fd("\" the ratio value in the ", 2);
		ft_putstr_fd(id, 2);
		ft_putendl_fd(" parameter should be within the [0.0,1.0] range", 2);
		return (1);
	}
	return (0);
}

int	check_rgb(char *arg, char *id)
{
	char	**rgb;
//	int		i;

	rgb = ft_split(arg, ',');
	if (array_len(rgb) != 3)
	{
		ft_putstr_fd("Error: \"", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\" the rgb parameter should have 3 values in the ", 2);
		ft_putstr_fd(id, 2);
		ft_putendl_fd(" parameter", 2);
		return (free_array(rgb), 1);
	}
/*	while (rgb[i])
	{
	//INT SYNTAX
	//RGB VALUE RANGE
		i++;
	}*/
	return (free_array(rgb), 0);
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
//		printf("%s", line[i]);
		elem = ft_split(line[i], ' ');
		if (element_id(elem[0]) == AMBIENT && ambient_error(elem))
			return (free_array(elem), 1);
/*		else if (element_id(elem[0]) == CAMERA)
			camera_error(elem);
		else if (element_id(elem[0]) == LIGHT)
			light_error(elem);
		else if (element_id(elem[0]) == SPHERE)
			sphere_error(elem);
		else if (element_id(elem[0]) == PLANE)
			plane_error(elem);
		else if (element_id(elem[0]) == CYLINDER)
			cylinder_error(elem);
*/		
		free_array(elem);
		i++;
	}
	return (0);
}
