/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:04 by wlin              #+#    #+#             */
/*   Updated: 2024/12/05 15:57:57 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "miniRT.h"

int hit_plane(t_ray ray, t_obj plane, double *t)
{
	double alignment;
	double to_plane[3];
	double plane_t;
	int hit = 0;

	alignment = vec_dot(ray.direction, plane.vc);
	if (fabs(alignment) < 1e-6) // Ray is parallel to the plane
		return (0);
	vec_sub(to_plane, plane.xyz, ray.origin);
	plane_t = vec_dot(to_plane, plane.vc) / alignment;
	if (plane_t < 0) // Intersection is behind the ray origin
		return (0);
	if (!hit || plane_t < *t)
	{
		*t = plane_t;
		hit = 1;
	}
	return (hit);
}
