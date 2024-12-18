/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/12/16 12:50:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool intersect_sphere(t_ray ray, t_obj sphere, t_hit_rec *rec)
{
	t_quad	hit;
	double	oc[3];

	vec_sub(oc, ray.origin, sphere.xyz);
	hit.a = vec_dot(ray.direction, ray.direction);
	hit.b = 2 * vec_dot(oc, ray.direction);
	hit.c = vec_dot(oc, oc) - (sphere.diam / 2) * (sphere.diam / 2);
	hit.discriminant = hit.b * hit.b - 4 * hit.a * hit.c;
	if (hit.discriminant < 0)
		return (false);
	hit.t1 = (-hit.b - sqrt(hit.discriminant)) / 2;
	hit.t2 = (-hit.b + sqrt(hit.discriminant)) / 2;
	if (hit.t1 >= 0.001 || hit.t1 <= rec->t)
		rec->t = hit.t1;
	else if (hit.t2 >= 0.001 || hit.t2 <= rec->t)
		rec->t = hit.t2;
	else
		return (false);
	ray_at_t(rec->p, ray, rec->t);
	vec_sub(rec->normal, rec->p, sphere.xyz);
	vec_div(rec->normal, (sphere.diam) / 2);
	return (true);
}
