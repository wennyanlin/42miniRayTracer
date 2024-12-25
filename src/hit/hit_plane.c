/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:04 by wlin              #+#    #+#             */
/*   Updated: 2024/12/24 17:45:18 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	hit_plane(t_ray ray, t_obj pl, t_hit_rec *rec)
{
	double	alignment;
	double	plane_t;
	double	aux;

	alignment = vec_dot(ray.direction, pl.vc);
	if (fabs(alignment) < 1e-6)
		return (false);
	aux = vec_dot(pl.vc, pl.xyz);
	plane_t = (aux - vec_dot(pl.vc, ray.origin)) / alignment;
	if (plane_t < 0.001 || plane_t > rec->t)
		return (false);
	rec->t = plane_t;
	ray_at_t(rec->p, ray, rec->t);
	vec_copy(rec->normal, pl.vc);
	return (true);
}
