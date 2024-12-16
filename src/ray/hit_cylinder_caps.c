/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_caps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:04 by wlin              #+#    #+#             */
/*   Updated: 2024/12/16 12:49:57 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	hit_cylinder_cap(t_ray ray, t_cap *cap, t_hit_rec *rec)
{
	double	alignment;
	double	oc[3];
	double	hit_point_to_c[3];
	double	hit_point[3];
	double	cap_t;

	alignment = vec_dot(ray.direction, cap->normal);
	if (fabs(alignment) < 0.000001)
		return (0);
	vec_sub(oc, cap->coordinates, ray.origin);
	cap_t = vec_dot(oc, cap->normal) / alignment;
	if (cap_t < 0.001 || cap_t > rec->t)
		return (0);
	ray_at_t(hit_point, ray, cap_t);
	vec_sub(hit_point_to_c, hit_point, cap->coordinates);
	if (vec_dot(hit_point_to_c, hit_point_to_c) > cap->radius * cap->radius)
		return (false);
	rec->t = cap_t;
	vec_copy(rec->p, hit_point);
	vec_scale(rec->normal, cap->normal, -1);
	return (false);
}

int	check_caps_hit(t_ray ray, t_obj cy, int *hit_flag, t_hit_rec *rec)
{
	t_cap	cap;

	vec_copy(cap.coordinates, cy.xyz);
	vec_copy(cap.center, cy.xyz);
	vec_copy(cap.normal, cy.vc);
	cap.radius = cy.diam/2;
	if (hit_cylinder_cap(ray, &cap, rec))
		*hit_flag = 1;
	vec_normalize(cap.normal);
	vec_scale(cap.center, cap.normal, cy.height);
	vec_add(cap.center, cap.center, cap.coordinates);
	vec_scale(cap.normal, cy.vc, -1);
	if (hit_cylinder_cap(ray, &cap, rec))
		*hit_flag = 1;
	return (*hit_flag);
}
