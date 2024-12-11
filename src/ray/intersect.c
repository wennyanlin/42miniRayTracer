/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/12/11 15:43:13 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool intersect_sphere(t_ray ray, t_obj sphere, double *t)
{
	double	oc[3];
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	root1;
	double	hit_point[3];
	double	normal_hit_point[3];

	vec_sub(oc, ray.origin, sphere.xyz);
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * vec_dot(oc, ray.direction);
	c = vec_dot(oc, oc) - (sphere.diam/2) * (sphere.diam/2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	root1 = (-b - sqrt(discriminant)) / 2;
	if (root1 < 0.001 || *t < root1)
	{
		 root1 = (-b + sqrt(discriminant)) / 2;
		 if (root1 <= 0.001 || *t <= root1)
		 	return (false);
	}
	*t = root1;
	ray_at_t(hit_point, ray, root1);
	vec_sub(normal_hit_point, hit_point, sphere.xyz);
	vec_div(normal_hit_point, (sphere.diam)/2);
	return (true);
}

