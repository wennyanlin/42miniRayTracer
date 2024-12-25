/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_caps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:04 by wlin              #+#    #+#             */
/*   Updated: 2024/12/26 00:02:37 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_cylinder_cap(t_ray ray, t_cap *cap, t_hit_rec *rec)
{
	float	alignment;
	float	oc[3];
	float	hit_point_to_c[3];
	float	hit_point[3];
	float	cap_t;

	alignment = vec_dot(ray.direction, cap->normal);
	if (fabs(alignment) < 0.000001)
		return (false);
	vec_sub(oc, cap->center, ray.origin);
	cap_t = vec_dot(oc, cap->normal) / alignment;
	if (cap_t < 0.001 || cap_t > rec->t)
		return (false);
	ray_at_t(hit_point, ray, cap_t);
	vec_sub(hit_point_to_c, hit_point, cap->center);
	if (vec_dot(hit_point_to_c, hit_point_to_c) > cap->radius * cap->radius)
		return (false);
	rec->t = cap_t;
	vec_copy(rec->p, hit_point);
	vec_copy(rec->normal, cap->normal);
	return (true);
}

bool	check_caps_hit(t_ray ray, t_obj cy, t_hit_rec *rec, bool *hit_flag)
{
	t_cap	cap;

	vec_copy(cap.center, cy.xyz);
	cap.radius = cy.diam / 2;
	vec_scale(cap.normal, cy.vc, -1);
	vec_normalize(cap.normal);
	if (hit_cylinder_cap(ray, &cap, rec))
		*hit_flag = 1;
	vec_copy(cap.normal, cy.vc);
	vec_scale(cap.center, cap.normal, cy.height);
	vec_add(cap.center, cap.center, cy.xyz);
	if (hit_cylinder_cap(ray, &cap, rec))
		*hit_flag = true;
	return (*hit_flag);
}
