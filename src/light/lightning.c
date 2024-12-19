/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:54:12 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/19 17:10:28 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	color_converter(int color[3], double intensity)
{
	int	r;
	int	g;
	int	b;

	r = (int)(intensity * color[0]);
	g = (int)(intensity * color[1]);
	b = (int)(intensity * color[2]);
	return ((r << 16) | (g << 8) | b);
}

double	lambert_law(double light_dir[3], double norm[3])
{
	double	intensity;

	intensity = vec_dot(light_dir, norm);
	if (intensity < 0)
		intensity = 0;
	return (intensity);
}

t_ray generate_ray_light(void *param, t_view view_params, int x, int y)
{
	t_ray	ray;
	double	view_right[3];
	double	view_up[3];
	double	normalized_x;
	double	normalized_y;
	
	// Ray starts from camera
	vec_copy(ray.origin, param->xyz);
	normalized_x = screen_x_to_viewport(x,
		view_params.aspect_ratio, view_params.fov_scale);
	normalized_y = screen_y_to_viewport(y, view_params.fov_scale);
	// Compute Ray Direction
	vec_scale(view_right, view_params.cam_right, normalized_x);
	vec_scale(view_up, view_params.cam_up, normalized_y);
	vec_add(ray.direction, view_right, view_up);
	vec_add(ray.direction, ray.direction, param->vc);
	vec_normalize(ray.direction);
	return (ray);
}

bool	hit_light(t_data *data)
{
	t_ray	ray;
	int		hit_flag;

	ray = generate_ray_light(data->light, data->view_param, x, y);
	while (obj != NULL)
	{
		//ray = generate_ray(*(data->cam), data->view_params, x, y);
		if (obj->id == PLANE)
			hit_flag = hit_plane(ray, *(obj), &rec);
		else if (obj->id == SPHERE)
			hit_flag = intersect_sphere(ray, *(obj), &rec);
		else if (obj->id == CYLINDER)
			hit_flag = hit_cylinder(ray, *(obj), &rec);
		if (hit_flag)
			return true;			
		obj = obj->next;
	}
	return false;
}

void	lightning(t_hit_rec *rec, t_data *data, int x, int y)
{
	double	light_dir[3];

	vec_sub(light_dir, data->light->xyz, rec->p);
	vec_normalize(light_dir);
	rec->intensity = lambert_law(light_dir, rec->normal) * data->light->ratio;
	if (!hit_light(data, x, y))
		rec->intensity = 0;
}
