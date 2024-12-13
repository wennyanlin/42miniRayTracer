/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:15:49 by wlin              #+#    #+#             */
/*   Updated: 2024/12/13 17:50:20 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//Computes the perpendicular components of ray.direction and the vector oc relative to the cylinder’s axis.
void	compute_perp(t_ray ray, t_obj cy, double dir_perp[3], double oc_perp[3])
{
	double	oc[3];
	
	vec_sub(oc, ray.origin, cy.xyz);//3D vector: ray_origin onto cylinder_center
	vec_project(dir_perp, ray.direction, cy.vc);//parallel component: ray_direction => cylinder_axis
	vec_sub(dir_perp, ray.direction, dir_perp);// perpendicular component from ray_direction
	vec_project(oc_perp, oc, cy.vc);// Project the oc vector (ray's origin to cylinder's base) onto the cylinder's axis
	vec_sub(oc_perp, oc, oc_perp);// Subtract the parallel component of oc from oc to get the perpendicular component
}

bool	find_hit_t(t_hit *hit, double *t)
{
	hit->discriminant = hit->b * hit->b - 4 * hit->a * hit->c;
	hit->t0 = (-hit->b - sqrt(hit->discriminant)) / (2.0 * hit->a);
	hit->t1 = (-hit->b + sqrt(hit->discriminant)) / (2.0 * hit->a);
	// Get the closest valid t(hit distance)
	if (hit->t0 > 0.001 && hit->t0 < *t)
		*t = hit->t0;
	else if (hit->t1 > 0.001 && hit->t1 < *t)
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
	projection = fabs(vec_dot(sub_result, cy.vc));
	if (projection >= 0 && projection <= cy.height)
		return (true);
	else
		return (false);
}

bool	hit_cylinder(t_ray ray, t_obj cy, double *t)
{
	t_hit	hit;
	double	d_perp[3];
	double	oc_perp[3];
	
	hit.hit_flag = 0;
	compute_perp(ray, cy, d_perp, oc_perp);
	hit.a = vec_dot(d_perp, d_perp);
	hit.b = 2 * vec_dot(d_perp, oc_perp);
	hit.c = vec_dot(oc_perp, oc_perp) - ((cy.diam / 2) * (cy.diam / 2));
	hit.discriminant = hit.b * hit.b - 4 * hit.a * hit.c;
	if (hit.discriminant < 0 || !find_hit_t(&hit, t))
		return (false);
	if (check_body_hit(ray, cy, t))
		hit.hit_flag = 1;
	if (check_caps_hit(ray, cy, t, &(hit.hit_flag)))
		hit.hit_flag = 1;
	return (hit.hit_flag);
}
