/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:54:12 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/24 16:40:17 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	color_converter(int color[3], double intensity)
{
	int r = (int)(intensity * color[0]);
	int g = (int)(intensity * color[1]);
	int b = (int)(intensity * color[2]);
	return (r << 16) | (g << 8) | b;
}

double	lambert_law(double light_dir[3], double norm[3])
{
	double	intensity;

	intensity = vec_dot(light_dir, norm);
	if (intensity < 0)
		intensity = 0;
	return (intensity);
}

void	lightning(t_hit_rec *rec, t_data *data)
{

	double	light_dir[3];

//	vec_sub(point->norm, point->xyz, data->obj->xyz);
//	vec_normalize(point->norm);
	vec_sub(light_dir, data->light->xyz, rec->p);
	vec_normalize(light_dir);
	rec->intensity = lambert_law(light_dir, rec->normal) * data->light->ratio;


//printf("x:%f, y:%f, z:%f\n", point->norm[0], point->norm[1], point->norm[0]);
//printf("intensity: %f\n", point->intensity);

}
