/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:04 by wlin              #+#    #+#             */
/*   Updated: 2024/12/20 18:33:08 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "miniRT.h"

bool hit_plane(t_ray ray, t_obj plane, t_hit_rec *rec)
{
	double	alignment;
	double	plane_t;
	double	aux;
	
//	rec->id = plane.id;
	alignment = vec_dot(ray.direction, plane.vc);
	if (fabs(alignment) < 1e-6)
		return (false);
	aux = vec_dot(plane.vc, plane.xyz);
	plane_t = (aux - vec_dot(plane.vc, ray.origin)) / alignment;
	if (plane_t < 0.001 || plane_t > rec->t)
		return (false);
	rec->t = plane_t;
	ray_at_t(rec->p, ray, rec->t);
	vec_copy(rec->normal, plane.vc);
	return (true);
}
