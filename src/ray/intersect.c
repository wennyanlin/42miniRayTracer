/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/11/25 18:33:40 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void vec_project(double *result, double *v, double *axis)
{
    double dot_product;
    double axis_length_squared;

    // Calculate the dot product of v and axis
    dot_product = vec_dot(v, axis);

    // Assume axis is normalized; otherwise, normalize it or divide by its length squared.
    axis_length_squared = vec_dot(axis, axis);

    // Scale the axis vector by the projection scalar
	vec_scale(result, axis, dot_product / axis_length_squared);
}
int ray_color(t_ray ray, t_obj sphere, double t) 
{
    double  result[3];

    if (t > 0.0) 
    {
        ray_at_t(result, ray, t);
        vec_sub(result, result, sphere.xyz);//result = nomal: a vector perpendicular to the hit point
        vec_normalize(result);
        vec_scale(result, (double [3]){result[0] + 1, result[1] + 1, result[2] + 1}, 0.5);
    }
    return (color_converter(result));
}

int intersect_sphere(t_ray ray, t_obj sphere, double *t)
{
	double  oc[3];
	double  a;
	double  b;
	double  c;
	double discriminant;
	
	vec_sub(oc, ray.origin, sphere.xyz);
	a = vec_dot(ray.direction, ray.direction);
	b = 2.0 * vec_dot(oc, ray.direction);
	c = vec_dot(oc, oc) - (sphere.diam/2) * (sphere.diam/2);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	else
	{
		*t = (-b - sqrt(discriminant)) / (2.0 * a);
		return (1);
	}
}

double vec_length(double *v)
{
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}


int intersect_plane(t_ray ray, double *plane_point, double *plane_normal, double radius, double *t)
{
    double denom;
    double to_plane[3];
    double p[3];

    denom = vec_dot(ray.direction, plane_normal);
    if (fabs(denom) < 1e-6) // Ray is parallel to the plane
        return (0);

    vec_sub(to_plane, plane_point, ray.origin);
    *t = vec_dot(to_plane, plane_normal) / denom;
    if (*t < 0) // Intersection is behind the ray origin
        return (0);
    // Compute intersection point
    vec_scale(p, ray.direction, *t);
    vec_add(p, p, ray.origin);
	vec_sub(to_plane, p, plane_point);
    // If radius > 0, validate intersection lies within circle of the given radius
    if (radius > 0)
    {
        double distance = vec_length(to_plane);
        if (distance > radius)
            return (0);
    }
    return (1); // Valid intersection
}

int	intersect_infinite_plane(t_ray ray, t_obj plane, double *t)
{
	double t_plane;
	int hit = 0;

	if (intersect_plane(ray, plane.xyz, plane.vc, 0, &t_plane))
	{
		if (!hit || t_plane < *t)
		{
			*t = t_plane;
			hit = 1;
		}
	}
	return (hit);
}
