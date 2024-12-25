/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:29:23 by wlin              #+#    #+#             */
/*   Updated: 2024/12/26 00:03:36 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*Checks how the two vectors are aligned.
 * @result
 * Zero => Perpendicular.
 * Positive => In the same direction.
 * Negative => In opposite direction.
 */
float	vec_dot(float a[3], float b[3])
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

/*Calulates a perpendiclar vector to another two perpendiculared vectors,
like the 3 axis x, y, z,  90 degress to each other in a corner in 3D space.
*/
void	vec_cross(float result[3], float a[3], float b[3])
{
	result[0] = a[1] * b[2] - a[2] * b[1];
	result[1] = a[2] * b[0] - a[0] * b[2];
	result[2] = a[0] * b[1] - a[1] * b[0];
}

/*Measuring distances between objects or points in space.*/
float	vec_length(float vec[3])
{
	return (sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
}

void	vec_normalize(float vec[3])
{
	float	magnitude;

	magnitude = vec_length(vec);
	if (magnitude > 0)
	{
		vec[0] /= magnitude;
		vec[1] /= magnitude;
		vec[2] /= magnitude;
	}
}

void	ray_at_t(float result[3], t_ray ray, float t)
{
	vec_scale(result, ray.direction, t);
	vec_add(result, ray.origin, result);
}
