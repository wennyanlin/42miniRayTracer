/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_caps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:04 by wlin              #+#    #+#             */
/*   Updated: 2024/12/12 10:04:09 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int hit_cylinder_cap(t_ray ray, t_obj cy, double *t)
{
	double alignment;
	double to_cap[3];
	double p[3];

	// Calculate if the ray intersects the plane of the cap
	alignment = vec_dot(ray.direction, cy.vc);
	if (fabs(alignment) < 1e-6) // Ray is parallel to the cap's plane
		return (0);
	vec_sub(to_cap, cy.xyz, ray.origin);
	*t = vec_dot(to_cap, cy.vc) / alignment;
	if (*t < 0.001) // Intersection is behind the ray origin
		return (0);
	// Compute the intersection point
	vec_scale(p, ray.direction, *t);
	vec_add(p, p, ray.origin);
	// Check if the intersection point lies within the cap's radius
	vec_sub(to_cap, p, cy.xyz);
	double distance = vec_length(to_cap);
	if (distance > (cy.diam / 2)) // Intersection is outside the cap's boundary
		return (0);
	return (1); // Valid intersection within the cap
}

int check_caps_hit(t_ray ray, t_obj cy, double *t, int *hit_flag)
{
	double cap_center[3];
	double cap_t;

	if (hit_cylinder_cap(ray, cy, &cap_t))
	{
		if (cap_t > 0.001 || cap_t < *t)
		{
			*t = cap_t;
			*hit_flag = 1;
		}
	}
	vec_scale(cap_center, cy.vc, cy.height);
	vec_add(cap_center, cap_center, cy.xyz);
	if (hit_cylinder_cap(ray, cy, &cap_t))
	{
		if (!*hit_flag || cap_t < *t)
		{
			*t = cap_t;
			*hit_flag = 1;
		}
	}
	return (*hit_flag);
}
