/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:40 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/26 18:00:58 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

void	fill_coordinates(char *coordinates, double *xyz)
{
	char	**xyz_array;
	int		i;

	xyz_array = ft_split(coordinates, ',');
	i = 0;
	while (i < 3)
	{
		xyz[i] = ft_atod(xyz_array[i]);
		free(xyz_array[i++]);
	}
	free(xyz_array);
}

void	init_ambient(char **elem, t_data *data)
{
	data->amb = malloc(sizeof(t_amb));
	if (!data->amb)
		system_error_free_data("malloc", data);
	data->amb->id = AMBIENT;
	data->amb->ratio = ft_atod(elem[1]);
	fill_rgb(elem[2], data->amb->rgb);
}

void	init_camera(char **elem, t_data *data)
{
	data->cam = malloc(sizeof(t_cam));
	if (!data->cam)
		system_error_free_data("malloc", data);
	data->cam->id = CAMERA;
	fill_coordinates(elem[1], data->cam->xyz);
	fill_coordinates(elem[2], data->cam->vc);
	data->cam->fov = ft_atoi(elem[3]);
}

void	init_light(char **elem, t_data *data)
{
	data->light = malloc(sizeof(t_light));
	if (!data->light)
		system_error_free_data("malloc", data);
	data->light->id = LIGHT;
	fill_coordinates(elem[1], data->light->xyz);
	data->light->ratio = ft_atod(elem[2]);
}
