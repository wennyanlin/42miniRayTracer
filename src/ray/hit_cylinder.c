/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:15:49 by wlin              #+#    #+#             */
/*   Updated: 2024/11/26 00:59:44 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	compute_perp(t_ray ray, t_obj cy, double dir_perp[3], double oc_perp[3])
{
	double	oc[3];
	
	vec_sub(oc, ray.origin, cy.xyz);//3D vector: ray_origin => cylinder_center
	vec_project(dir_perp, ray.direction, cy.vc);//parallel component: ray_direction => cylinder_axis
	vec_sub(dir_perp, ray.direction, dir_perp);// Subtract the parallel component from the ray's direction to get the perpendicular component
	vec_project(oc_perp, oc, cy.vc);// Project the oc vector (ray's origin to cylinder's base) onto the cylinder's axis
	vec_sub(oc_perp, oc, oc_perp);// Subtract the parallel component of oc from oc to get the perpendicular component
}

bool	find_hit_t(t_hit *hit, double *t)
{
	hit->discriminant = hit->b * hit->b - 4 * hit->a * hit->c;
	hit->t0 = (-hit->b - sqrt(hit->discriminant)) / (2.0 * hit->a);
	hit->t1 = (-hit->b + sqrt(hit->discriminant)) / (2.0 * hit->a);
	// Get the closest valid t(hit distance)
	if (hit->t0 > 0)
		*t = hit->t0;
	else if (hit->t1 > 0)
		*t = hit->t1;
	else
		return (false);
	return (true);
}

bool	check_body_hit(t_ray ray, t_obj cy, double *t)
{
	double	projection;
	double	sub_result[3];
	double	hit_point[3];
	
	vec_scale(hit_point, ray.direction, *t);
	vec_add(hit_point, hit_point, ray.origin);
	vec_sub(sub_result, hit_point, cy.xyz);
	projection = vec_dot(sub_result, cy.vc);
	if (projection >= 0 && projection <= cy.height)
		return (true);
	else
		return (false);
}

int	check_caps_hit(t_ray ray, t_obj cy, double *t, int *hit_flag)
{
	double	cap_center[3];
	double	cap_t;

	// Bottom cap
	if (intersect_plane(ray, cy.xyz, cy.vc, cy.diam / 2, &cap_t))
	{
		if (!*hit_flag || cap_t < *t)
		{
			*t = cap_t;
			*hit_flag = 1;
		}
	}
	// Top cap
	vec_scale(cap_center, cy.vc, cy.height);
	vec_add(cap_center, cap_center, cy.xyz);
	if (intersect_plane(ray, cap_center, cy.vc, cy.diam / 2, &cap_t)
		&& (!*hit_flag || cap_t < *t))
	{
		*t = cap_t;
		*hit_flag = 1;
	}
	return (*hit_flag);
}

int	hit_cylinder(t_ray ray, t_obj cy, double *t)
{
	t_hit	hit;
	double	d_perp[3];
	double	oc_perp[3];
	
	hit.hit_flag = 0;
	compute_perp(ray, cy, d_perp, oc_perp);
	hit.a = vec_dot(d_perp, d_perp);
	hit.b = 2.0 * vec_dot(d_perp, oc_perp);
	hit.c = vec_dot(oc_perp, oc_perp) - ((cy.diam / 2) * (cy.diam / 2));
	hit.discriminant = hit.b * hit.b - 4 * hit.a * hit.c;
	if (hit.discriminant < 0 || !find_hit_t(&hit, t))
		return (0);
	if (check_body_hit(ray, cy, t))
		hit.hit_flag = 1;
	if (check_caps_hit(ray, cy, t, &(hit.hit_flag)))
		hit.hit_flag = 1;
	return (hit.hit_flag);
}
