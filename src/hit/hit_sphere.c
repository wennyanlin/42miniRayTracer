/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/12/19 17:30:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	solve_quadratic_t(t_quad quad, float last_closest_t, float *new_t)
{
	quad.t1 = (-quad.b - sqrt(quad.discriminant)) / (2 * quad.a);
	quad.t2 = (-quad.b + sqrt(quad.discriminant)) / (2 * quad.a);
	if (quad.t1 > 0.000001 && quad.t1 < last_closest_t)
		*new_t = quad.t1;
	else if (quad.t2 > 0.000001 && quad.t2 < last_closest_t)
		*new_t = quad.t2;
	else
		return (false);
	return (true);
}

bool hit_sphere(t_ray ray, t_obj sp, t_hit_rec *rec)
{
	t_quad	quad;
	float	oc[3];
	float	hit_t;

	vec_sub(oc, ray.origin, sp.xyz);
	quad.a = vec_dot(ray.direction, ray.direction);
	quad.b = 2 * vec_dot(oc, ray.direction);
	quad.c = vec_dot(oc, oc) - (sp.diam / 2) * (sp.diam / 2);
	quad.discriminant = quad.b * quad.b - 4 * quad.a * quad.c;
	if (quad.discriminant < 0)
		return (false);
	if (!solve_quadratic_t(quad, rec->t, &hit_t))
		return (false);
	rec->t = hit_t;
	ray_at_t(rec->p, ray, rec->t);
	vec_sub(rec->normal, rec->p, sp.xyz);
	vec_div(rec->normal, (sp.diam) / 2);
	return (true);
}
