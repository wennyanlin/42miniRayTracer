/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:44:04 by wlin              #+#    #+#             */
/*   Updated: 2024/12/11 17:11:06 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "miniRT.h"

int hit_plane(t_ray ray, t_obj plane, double *t)
{
	double alignment;
	double plane_t;
	double	hit_point[3];
	double	aux;

	alignment = vec_dot(ray.direction, plane.vc);
	if (fabs(alignment) < 1e-6)
		return (0);
	aux = vec_dot(plane.vc, plane.xyz);
	plane_t = (aux - vec_dot(plane.vc, ray.origin)) / alignment;
	if (plane_t < 0.001 || plane_t > *t)
		return (false);
	*t = plane_t;
	ray_at_t(hit_point, ray, *t);
	return (1);
}