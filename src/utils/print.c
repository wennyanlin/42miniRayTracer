/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:41:09 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 17:46:44 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data(t_data *data)
{
	printf("ambient: id:%s, ratio:%.2f, rgb:%d %d %d\n", data->amb->id, \
	data->amb->ratio, data->amb->rgb[0], data->amb->rgb[1], data->amb->rgb[2]);
	printf("camera: id:%s, coordinates: %.2f %.2f %.2f, vectors: %.2f %.2f %.2f, fov:%d\n", data->cam->id, data->cam->xyz[0], data->cam->xyz[1], \
	data->cam->xyz[2], data->cam->vc[0], data->cam->vc[1], data->cam->vc[2], \
	data->cam->fov); 
	printf("light: id:%s, coordinates: %.2f %.2f %.2f, ratio: %.2f\n", \
	data->light->id, data->light->xyz[0], data->light->xyz[1], \
	data->light->xyz[2], data->light->ratio); 
}
