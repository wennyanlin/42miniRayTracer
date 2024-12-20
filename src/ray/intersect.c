/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/12/20 18:33:08 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool intersect_sphere(t_ray ray, t_obj sphere, t_hit_rec *rec)
{
	t_quad	quad;
	double	oc[3];
	double	hit_t;

//	rec->id = sphere.id;
	vec_sub(oc, ray.origin, sphere.xyz);
	quad.a = vec_dot(ray.direction, ray.direction);
	quad.b = 2 * vec_dot(oc, ray.direction);
	quad.c = vec_dot(oc, oc) - (sphere.diam / 2) * (sphere.diam / 2);
	quad.discriminant = quad.b * quad.b - 4 * quad.a * quad.c;
	if (quad.discriminant < 0)
		return (false);
	if (!solve_quadratic_t(quad, rec->t, &hit_t))
		return (false);
	rec->t = hit_t;
	ray_at_t(rec->p, ray, rec->t);
	vec_sub(rec->normal, rec->p, sphere.xyz);
	vec_div(rec->normal, (sphere.diam) / 2);
	return (true);
}
