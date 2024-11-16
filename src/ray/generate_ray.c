/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:14:21 by wlin              #+#    #+#             */
/*   Updated: 2024/11/16 15:23:29 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"



t_ray generate_ray(t_cam camera, t_view view_params, int x, int y, int screen_width, int screen_height)
{
	t_ray	ray;
	double	scaled_right[3];
	double	scaled_up[3];
	
	// Ray starts from camera
	vec_copy(ray.origin, camera.xyz);
	
	// Calculate Normalized Coordinates for Screen Space
	double normalized_x = (2.0 * (x + 0.5) / (double)screen_width - 1.0) * view_params.aspect_ratio * view_params.scale;
	double normalized_y = (1.0 - 2.0 * (y + 0.5) / (double)screen_height) * view_params.scale;

	// Compute Ray Direction
	vec_scale(scaled_right, view_params.cam_right, normalized_x);
	vec_scale(scaled_up, view_params.cam_up, normalized_y);

	double ray_direction[3];
	vec_add(ray_direction, scaled_right, scaled_up);
	vec_add(ray_direction, ray_direction, camera.vc);
	vec_normalize(ray_direction);
	vec_copy(ray.direction, ray_direction);
	return (ray);
}
