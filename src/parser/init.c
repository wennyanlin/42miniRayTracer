/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:14 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/25 18:48:29 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_ambient(char **elem, t_data *data)
{
	data->amb = malloc(sizeof(t_amb));
	if (!data->amb)
		system_error_free_data("malloc", data);
	data->amb->id = AMBIENT;
	data->amb->ratio = ft_atod(elem[1]);
	fill_rgb(elem[2], data->amb->rgb);
}

static void	init_camera(char **elem, t_data *data)
{
	data->cam = malloc(sizeof(t_cam));
	if (!data->cam)
		system_error_free_data("malloc", data);
	data->cam->id = CAMERA;
	fill_coordinates(elem[1], data->cam->xyz);
	fill_coordinates(elem[2], data->cam->vc);
	vec_normalize(data->cam->vc);
	data->cam->fov = ft_atoi(elem[3]);
}

static void	init_light(char **elem, t_data *data)
{
	data->light = malloc(sizeof(t_light));
	if (!data->light)
		system_error_free_data("malloc", data);
	data->light->id = LIGHT;
	fill_coordinates(elem[1], data->light->xyz);
	data->light->ratio = ft_atod(elem[2]);
}

static void	initialize_data(t_data *data)
{
	data->conn = NULL;
	data->win = NULL;
	data->img = NULL;
	data->amb = NULL;
	data->cam = NULL;
	data->light = NULL;
	data->obj = NULL;
}

void	init(char *file, t_data *data)
{
	char	**line;
	char	**elem;
	int		i;

	line = copy_elements(file);
	i = 0;
	initialize_data(data);
	while (line[i])
	{
		elem = ft_split(line[i], ' ');
		if (element_id(elem[0]) == AMBIENT)
			init_ambient(elem, data);
		else if (element_id(elem[0]) == CAMERA)
			init_camera(elem, data);
		else if (element_id(elem[0]) == LIGHT)
			init_light(elem, data);
		else if (element_id(elem[0]) >= SPHERE)
			init_objects(elem, &data->obj, data);
		free_array(elem);
		free(line[i++]);
	}
	free(line);
}
