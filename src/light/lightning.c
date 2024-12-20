/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:54:12 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/20 18:32:17 by cle-tron         ###   ########.fr       */
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
bool	hit_light(t_data *data, double light_dir[3], t_hit_rec *rec)
{
	t_ray		ray;
	int			hit_flag;
	t_obj		*obj;
	t_hit_rec	*rec_sh;
	double		scale[3];

	rec_sh = rec;
	//rec_sh->t = 2147483647;
	obj = data->obj;
//	vec_copy(ray.origin, rec_sh->p);
	vec_scale(scale, rec_sh->normal, 0.001);
	vec_add(ray.origin, rec_sh->p, scale); 
	vec_copy(ray.direction, light_dir);

//	double		light_distance; // if rec_sh->t > ligth_distance retur true
//	double		tmp_vc[3];
//	vec_sub(tmp_vc, data->light->xyz, rec_sh->p);
//	light_distance = vec_length(tmp_vc);
	

	hit_flag = 0;
	while (obj != NULL)
	{
		if (obj->id == PLANE)
			hit_flag = hit_plane(ray, *(obj), rec_sh);
		else if (obj->id == SPHERE)
			hit_flag = intersect_sphere(ray, *(obj), rec_sh);
		else if (obj->id == CYLINDER)
			hit_flag = hit_cylinder(ray, *(obj), rec_sh);
		if (hit_flag ) // && obj->id != rec_sh->id)
		{
		//	printf("%f\n", rec_sh->t);
			return true;			
		}
		obj = obj->next;
	}
	//return hit_flag;
	return false;
}

void	lightning(t_hit_rec *rec, t_data *data)
{
	double	light_dir[3];

	vec_sub(light_dir, data->light->xyz, rec->p);
	vec_normalize(light_dir);
	rec->intensity = lambert_law(light_dir, rec->normal) * data->light->ratio;		if (hit_light(data, light_dir, rec))
	{
		printf("%f\n", rec->t);
	rec->intensity = 0;
	}
}
