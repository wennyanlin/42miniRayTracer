/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:54:12 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/22 14:39:03 by cle-tron         ###   ########.fr       */
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
bool	hit_light(t_data *data, double light_dir[3], t_hit_rec *rec, int y, int x)
{
	t_ray		ray;
	int			hit_flag;
	t_obj		*obj;
	t_hit_rec	tmp_rec;
	double		scale[3];

	(void)light_dir;
//	rec_sh = rec;
//	rec->t = 2147483647;
	obj = data->obj;
//	vec_copy(ray.origin, rec_sh->p);
	vec_scale(scale, rec->normal, 0.001);
	vec_add(ray.origin, rec->p, scale); 
//	vec_copy(ray.direction, light_dir);
	vec_sub(ray.direction, data->light->xyz, ray.origin);
	vec_normalize(ray.direction);

	double		light_distance; // if rec_sh->t > ligth_distance retur true
	double		tmp_vc[3];
	vec_sub(tmp_vc, data->light->xyz, ray.origin);
	light_distance = vec_length(tmp_vc);
	double min_distance = light_distance;
	hit_flag = false;
	if ((y == 300 && x == 700) || (y == 300 && x == 600))
		printf("light_distance:\t\t%f\n", light_distance);
//(void)y;	

//	hit_flag = 0;
	//printf("%d ", rec->id);
	while (obj != NULL)
	{
	//	hit_flag = 0;
	//	rec->t = 2147483647;
	//	if (obj == &(rec->curr_obj))
	//	{
	//		obj = obj->next;
	//		continue;
	//	}
		tmp_rec = *rec;
		tmp_rec.t = light_distance;
		if (obj->id == PLANE && hit_plane(ray, *obj, &tmp_rec)  )
		{
			if (tmp_rec.t < min_distance)
			{
				min_distance = tmp_rec.t;
				hit_flag = true;

			}

			//hit_flag = hit_plane(ray, *obj, rec);
		}
		else if (obj->id == SPHERE &&  intersect_sphere(ray, *obj, &tmp_rec))
		{
		//	hit_flag = intersect_sphere(ray, *obj, rec);
	//		if (hit_flag) printf("s");
			if (tmp_rec.t < min_distance)
			{
				min_distance = tmp_rec.t;
				hit_flag = true;

			}
		}
		else if (obj->id == CYLINDER &&    hit_cylinder(ray, *obj, &tmp_rec)  )
		{
		//	hit_flag = hit_cylinder(ray, *obj, rec);
	//		if (hit_flag) printf("c");
			if (tmp_rec.t < min_distance)
			{
				min_distance = tmp_rec.t;
				hit_flag = true;
			}
		}
	//	if (hit_flag && (rec->t <= light_distance))// && obj->id == rec_sh->id)
	//		return true;			
		obj = obj->next;
	}
	return hit_flag && min_distance <= light_distance;
}

void	lightning(t_hit_rec *rec, t_data *data, int y, int x)
{
	double	light_dir[3];

	vec_sub(light_dir, data->light->xyz, rec->p);
	vec_normalize(light_dir);
	rec->intensity = lambert_law(light_dir, rec->normal) * data->light->ratio;	


//	if (rec->id == SPHERE) {
	if (hit_light(data, light_dir, rec, y, x))	{
	//	printf("%f\n", rec->t);
	rec->intensity = 0;}
	//}
	rec->intensity += data->amb->ratio;
	if (rec->intensity > 1)
		rec->intensity = 1;
}
