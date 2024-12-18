/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/12/16 18:20:00 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool intersect_sphere(t_ray ray, t_obj sphere, t_hit_rec *rec)
{
	t_quad	quad;
	double	oc[3];

	vec_sub(oc, ray.origin, sphere.xyz);
	quad.a = vec_dot(ray.direction, ray.direction);
	quad.b = 2 * vec_dot(oc, ray.direction);
	quad.c = vec_dot(oc, oc) - (sphere.diam / 2) * (sphere.diam / 2);
	quad.discriminant = quad.b * quad.b - 4 * quad.a * quad.c;
	if (quad.discriminant < 0)
		return (false);
	quad.t1 = (-quad.b - sqrt(quad.discriminant)) / 2;
	quad.t2 = (-quad.b + sqrt(quad.discriminant)) / 2;
	if (quad.t1 >= 0.001 || quad.t1 <= rec->t)
		rec->t = quad.t1;
	else if (quad.t2 >= 0.001 || quad.t2 <= rec->t)
		rec->t = quad.t2;
	else
		return (false);
	ray_at_t(rec->p, ray, rec->t);
	vec_sub(rec->normal, rec->p, sphere.xyz);
	vec_div(rec->normal, (sphere.diam) / 2);
	return (true);
}
