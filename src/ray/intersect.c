/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/12/04 15:00:21 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int ray_color(t_ray ray, t_obj sphere, double t) 
{
	double  result[3];

	if (t > 0) 
	{
		ray_at_t(result, ray, t);
		vec_sub(result, result, sphere.xyz);//result = nomal: a vector perpendicular to the hit point
		vec_normalize(result);
		vec_scale(result, (double [3]){result[0] + 1, result[1] + 1, result[2] + 1}, 0.5);
	}
	return (color_converter(result));
}

bool intersect_sphere(t_ray ray, t_obj sphere, double *t)
{
	double	oc[3];
	double	a;
	double	b;
	double	c;
	double	discriminant;

	vec_sub(oc, ray.origin, sphere.xyz);
	a = vec_dot(ray.direction, ray.direction);
	b = 2 * vec_dot(oc, ray.direction);
	c = vec_dot(oc, oc) - (sphere.diam/2) * (sphere.diam/2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	else
	{
		*t = (-b - sqrt(discriminant)) / (2 * a);
		return (true);
	}
}

