/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:40 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 17:46:11 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_ambient(char **elem, t_data *data)
{
	data->amb = malloc(sizeof(t_amb));
	data->amb->id = ft_strdup(elem[0]);
	data->amb->ratio = ft_atod(elem[1]);
	fill_rgb(elem[2], data->amb->rgb);
}

void	init_camera(char **elem, t_data *data)
{
	data->cam = malloc(sizeof(t_cam));
	data->cam->id = ft_strdup(elem[0]);
	fill_coordinates(elem[1], data->cam->xyz);
	fill_coordinates(elem[2], data->cam->vc);
	data->cam->fov = ft_atoi(elem[3]);
}

void	init_light(char **elem, t_data *data)
{
	data->light = malloc(sizeof(t_light));
	data->light->id = ft_strdup(elem[0]);
	fill_coordinates(elem[1], data->light->xyz);
	data->light->ratio = ft_atod(elem[2]);
}
