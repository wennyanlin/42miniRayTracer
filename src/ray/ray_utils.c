/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:42:57 by wlin              #+#    #+#             */
/*   Updated: 2024/12/24 17:42:24 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//For Debug
// int	normal_color(double normal[3])
// {
// 	int r = (int)(255.999 * ((normal[0] + 1) / 2));
// 	int g = (int)(255.999 * ((normal[1] + 1) / 2));
// 	int b = (int)(255.999 * ((normal[2] + 1) / 2));
// 	return (r << 16) | (g << 8) | b;
// }

// int ray_color(t_ray ray, t_obj sphere, double t) 
// {
// 	double	result[3];

// 	if (t > 0)
// 	{
// 		ray_at_t(result, ray, t);
// 		vec_sub(result, result, sphere.xyz);//result = nomal: a vector perpendicular to the hit point
// 		vec_normalize(result);
// 		vec_scale(result, (double [3]){result[0] + 1, result[1] + 1,
// 			result[2] + 1}, 0.5);
// 	}
// 	return (color_converter(result));
// }
