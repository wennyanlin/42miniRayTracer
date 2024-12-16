/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:29:23 by wlin              #+#    #+#             */
/*   Updated: 2024/12/16 02:40:24 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	vec_add(double result[3], double a[3], double b[3])
{
	result[0] = a[0] + b[0];
	result[1] = a[1] + b[1];
	result[2] = a[2] + b[2];
}

/*Measuring distances between objects or points in space.*/
double	vec_length(double vec[3])
{
	return (sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
}

void	vec_normalize(double vec[3])
{
	double	magnitude;
	
	magnitude = vec_length(vec);
	if (magnitude > 0)
	{
		vec[0] /= magnitude;
		vec[1] /= magnitude;
		vec[2] /= magnitude;
	}
}

/*Va - Vb => Va + (-Vb)*/
void	vec_sub(double result[3], double a[3], double b[3])
{
	result[0] = a[0] - b[0];
	result[1] = a[1] - b[1];
	result[2] = a[2] - b[2];
}
void	vec_scale(double result[3], double vec[3], double scalar)
{
	result[0] = vec[0] * scalar;
	result[1] = vec[1] * scalar;
	result[2] = vec[2] * scalar;
}

/*Checks how the two vectors are aligned.
 * @result
 * Zero => Perpendicular.
 * Positive => In the same direction.
 * Negative => In opposite direction.
 */
double	vec_dot(double a[3], double b[3])
{
	return (a[0] * b[0] + 
			a[1] * b[1] + 
			a[2] * b[2]);
}

/*Calulates a perpendiclar vector to another two perpendiculared vectors,
like the 3 axis x, y, z,  90 degress to each other in a corner in 3D space.
*/
void	vec_cross(double result[3], double a[3], double b[3])
{
	result[0] = a[1] * b[2] - a[2] * b[1];
	result[1] = a[2] * b[0] - a[0] * b[2];
	result[2] = a[0] * b[1] - a[1] * b[0];
}

void	vec_div(double vec[3], double scalar)
{
	vec[0] /= scalar;
	vec[1] /= scalar;
	vec[2] /= scalar;
}

void	ray_at_t(double result[3], t_ray ray, double t)
{
	vec_scale(result, ray.direction, t);
	vec_add(result, ray.origin, result);
}
