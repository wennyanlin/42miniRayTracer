/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:15:49 by wlin              #+#    #+#             */
/*   Updated: 2024/12/16 02:56:14 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_body_hit(t_ray ray, t_obj cy, t_quad *quad, t_hit_rec *rec)
{
	double	projection;
	double	sub_result[3];
	double	hit_point[3];
	double	axis[3];
	double	tmp[3];
	double	base_to_hit[3];

	quad->t1 = (-quad->b - sqrt(quad->discriminant)) / (2 * quad->a);
	quad->t2 = (-quad->b + sqrt(quad->discriminant)) / (2 * quad->a);
	if (quad->t1 > 0.000001 && quad->t1 < rec->t)
		rec->t = quad->t1;
	else if (quad->t2 > 0.000001 && quad->t2 < rec->t)
		rec->t = quad->t2;
	else
		return (false);
	vec_scale(hit_point, ray.direction, rec->t);
	vec_add(hit_point, hit_point, ray.origin);
	vec_copy(axis, cy.vc);
	vec_normalize(axis);
	vec_sub(sub_result, hit_point, cy.xyz);
	projection = vec_dot(sub_result, axis);
	if (projection < 0 || projection > cy.height)
		return (false);
	vec_copy(rec->p, hit_point);
	vec_scale(tmp, axis, projection);
	vec_sub(base_to_hit, sub_result, tmp);
	vec_normalize(base_to_hit);
	vec_copy(rec->normal, base_to_hit);
	return (true);
}

bool hit_cylinder(t_ray ray, t_obj cy, t_hit_rec *rec)
{
	t_quad	quad;
	double	oc[3];
	double	oc_perp[3];
	double	dir_perp[3];
	double	axis[3];

	quad.hit_flag = 0;
	vec_sub(oc, ray.origin, cy.xyz);
	vec_copy(axis, cy.vc);
	vec_normalize(axis);
	vec_cross(dir_perp, ray.direction, axis);
	vec_cross(oc_perp, oc, axis);
	quad.a = vec_dot(dir_perp, dir_perp);
	quad.b = 2 * vec_dot(dir_perp, oc_perp);
	quad.c = vec_dot(oc_perp, oc_perp) - ((cy.diam / 2) * (cy.diam / 2));
	quad.discriminant = quad.b * quad.b - 4 * quad.a * quad.c;
	if (quad.discriminant < 0)
		return (false);
	if (check_body_hit(ray, cy, &quad, rec))
		quad.hit_flag = 1;
	if (check_caps_hit(ray, cy, &(quad.hit_flag), rec))
		quad.hit_flag = 1;
	return (quad.hit_flag);
}
