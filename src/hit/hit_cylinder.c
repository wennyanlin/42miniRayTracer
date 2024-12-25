/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:15:49 by wlin              #+#    #+#             */
/*   Updated: 2024/12/24 17:44:06 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_normal(t_hit_rec *rec, double *base_to_p, double axis[3], double proj)
{
	double	scaled_axis[3];

	vec_scale(scaled_axis, axis, proj);
	vec_sub(rec->normal, base_to_p, scaled_axis);
	vec_normalize(rec->normal);
}

bool	check_body_hit(t_ray ray, t_obj cy, t_hit_rec *rec, t_quad *quad)
{
	double	projection_on_axis;
	double	base_to_hit_point[3];
	double	hit_point[3];
	double	cy_axis[3];
	double	hit_t;

	if (!solve_quadratic_t(*quad, rec->t, &hit_t))
		return (false);
	ray_at_t(hit_point, ray, hit_t);
	vec_copy(cy_axis, cy.vc);
	vec_normalize(cy_axis);
	vec_sub(base_to_hit_point, hit_point, cy.xyz);
	projection_on_axis = vec_dot(base_to_hit_point, cy_axis);
	if (projection_on_axis < 0 || projection_on_axis > cy.height)
		return (false);
	rec->t = hit_t;
	vec_copy(rec->p, hit_point);
	set_normal(rec, base_to_hit_point, cy_axis, projection_on_axis);
	return (true);
}

bool	hit_cylinder(t_ray ray, t_obj cy, t_hit_rec *rec)
{
	t_quad	quad;
	double	oc[3];
	double	oc_perp[3];
	double	dir_perp[3];
	double	axis[3];

	quad.hit_flag = false;
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
	if (check_caps_hit(ray, cy, rec, &(quad.hit_flag)))
		quad.hit_flag = true;
	if (check_body_hit(ray, cy, rec, &quad))
		quad.hit_flag = true;
	return (quad.hit_flag);
}
