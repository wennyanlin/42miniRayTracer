/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:42:57 by wlin              #+#    #+#             */
/*   Updated: 2024/12/08 15:52:15 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	vec_copy(double vec_dest[3], double vec_src[3])
{
	vec_dest[0] = vec_src[0];
	vec_dest[1] = vec_src[1];
	vec_dest[2] = vec_src[2];
}

void	print_vec_value(double vec[3], int num)
{
	printf("%d: x: %f, y: %f, z: %f\n", num, vec[0], vec[1], vec[2]);
}

int	color_converter(double color[3])
{
	int r = (int)(255 * color[0]);
	int g = (int)(255 * color[1]);
	int b = (int)(255 * color[2]);
	printf("5: x: %d, y: %d, z: %d\n", r, g, b);
	return (r << 16) | (g << 8) | b;
}

int ray_color(t_ray ray, t_obj sphere, double t) 
{
	double	result[3];

	if (t > 0)
	{
		ray_at_t(result, ray, t);
	//	print_vec_value(result, 1);
		vec_sub(result, result, sphere.xyz);//result = nomal: a vector perpendicular to the hit point
	//	print_vec_value(result, 2);
		vec_normalize(result);
	//	print_vec_value(result, 3);
		vec_scale(result, (double [3]){result[0] + 1, result[1] + 1,
			result[2] + 1}, 0.5);

	//	print_vec_value(result, 4);
	}
	return (color_converter(result));
//	return ((int)result[0] << 16) | ((int)result[1] << 8) | (int)result[2];
}
