/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:42:57 by wlin              #+#    #+#             */
/*   Updated: 2024/12/26 00:01:34 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//For Debug
// int	normal_color(float normal[3])
// {
// 	int r = (int)(255.999 * ((normal[0] + 1) / 2));
// 	int g = (int)(255.999 * ((normal[1] + 1) / 2));
// 	int b = (int)(255.999 * ((normal[2] + 1) / 2));
// 	return (r << 16) | (g << 8) | b;
// }

// int ray_color(t_ray ray, t_obj sphere, float t) 
// {
// 	float	result[3];

// 	if (t > 0)
// 	{
// 		ray_at_t(result, ray, t);
// 		vec_sub(result, result, sphere.xyz);//result = nomal: a vector perpendicular to the hit point
// 		vec_normalize(result);
// 		vec_scale(result, (float [3]){result[0] + 1, result[1] + 1,
// 			result[2] + 1}, 0.5);
// 	}
// 	return (color_converter(result));
// }
