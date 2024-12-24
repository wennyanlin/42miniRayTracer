/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:19:29 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/24 15:26:34 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "miniRT.h"

bool	closest_object(double intersection_distance, double min_distance)
{
	if (intersection_distance < min_distance)
	{
		min_distance = intersection_distance;
		return (true);
	}
	return (false);
}

t_ray	generate_light_ray(t_hit_rec *rec, double xyz_light[3])
{
	double		scale[3];
	t_ray		ray;

	vec_scale(scale, rec->normal, 0.001);
	vec_add(ray.origin, rec->p, scale);
	vec_sub(ray.direction, xyz_light, ray.origin);
	vec_normalize(ray.direction);
	return (ray);
}

double	calc_light_distance(double xyz_light[3], double ray_origin[3])
{
	double		tmp_vc[3];

	vec_sub(tmp_vc, xyz_light, ray_origin);
	return (vec_length(tmp_vc));
}

bool	calc_shadows(t_data *data, t_hit_rec *rec)
{
	t_ray		ray;
	int			hit_flag;
	t_obj		*obj;
	t_hit_rec	tmp_rec;
	double		min_distance;

	obj = data->obj;
	ray = generate_light_ray(rec, data->light->xyz);
	rec->light_distance = calc_light_distance(data->light->xyz, ray.origin);
	min_distance = rec->light_distance;
	hit_flag = false;
	while (obj != NULL)
	{
		tmp_rec = *rec;
		tmp_rec.t = rec->light_distance;
		if (obj->id == PLANE && hit_plane(ray, *obj, &tmp_rec))
			hit_flag = closest_object(tmp_rec.t, min_distance);
		else if (obj->id == SPHERE && intersect_sphere(ray, *obj, &tmp_rec))
			hit_flag = closest_object(tmp_rec.t, min_distance);
		else if (obj->id == CYLINDER && hit_cylinder(ray, *obj, &tmp_rec))
			hit_flag = closest_object(tmp_rec.t, min_distance);
		obj = obj->next;
	}
	return (hit_flag && min_distance <= rec->light_distance);
}
