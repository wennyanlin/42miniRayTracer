/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:41:09 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/14 14:33:28 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data(t_data *data)
{
	printf("\nambient: id:%d, ratio:%.2f, rgb:%d %d %d\n", data->amb->id, \
	data->amb->ratio, data->amb->rgb[0], data->amb->rgb[1], data->amb->rgb[2]);
	printf("camera: id:%d, coordinates: %.2f %.2f %.2f, vectors: %.2f %.2f %.2f, fov:%d\n", data->cam->id, data->cam->xyz[0], data->cam->xyz[1], \
	data->cam->xyz[2], data->cam->vc[0], data->cam->vc[1], data->cam->vc[2], \
	data->cam->fov); 
	printf("light: id:%d, coordinates: %.2f %.2f %.2f, ratio: %.2f\n", \
	data->light->id, data->light->xyz[0], data->light->xyz[1], \
	data->light->xyz[2], data->light->ratio);
	t_obj *tmp;
	tmp = data->obj;
	while (data->obj)
	{
		if (data->obj->id == SPHERE)
			printf("sphere: id:%d,  coordinates: %.2f %.2f %.2f, diam:%.2f, rgb:%d %d %d\n", data->obj->id, data->obj->xyz[0], data->obj->xyz[1], data->obj->xyz[2], data->obj->diam, data->obj->rgb[0], data->obj->rgb[1], data->obj->rgb[2]);
		else if (data->obj->id == PLANE)
			printf("plane: id:%d,  coordinates: %.2f %.2f %.2f, vc: %.2f %.2f %.2f, rgb:%d %d %d\n", data->obj->id, data->obj->xyz[0], data->obj->xyz[1], data->obj->xyz[2], data->obj->vc[0], data->obj->vc[1], data->obj->vc[2], data->obj->rgb[0], data->obj->rgb[1], data->obj->rgb[2]);
		else if (data->obj->id == CYLINDER)
			printf("cylinder: id:%d,  coordinates: %.2f %.2f %.2f, vc: %.2f %.2f %.2f, diam:%.2f, height:%.2f, rgb:%d %d %d\n", data->obj->id, data->obj->xyz[0], data->obj->xyz[1], data->obj->xyz[2], data->obj->vc[0], data->obj->vc[1], data->obj->vc[2], data->obj->diam, data->obj->height, data->obj->rgb[0], data->obj->rgb[1], data->obj->rgb[2]);
		data->obj = data->obj->next;
	}
	data->obj = tmp;
}
