/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:14:21 by wlin              #+#    #+#             */
/*   Updated: 2024/12/19 17:30:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	screen_x_to_viewport(int x, float aspect_ratio, float fov_scale)
{
	return ((2.0 * (x + 0.5) / (float)WIDTH - 1.0) * aspect_ratio * fov_scale);
}

float	screen_y_to_viewport(int y, float fov_scale)
{
	return ((1.0 - 2.0 * (y + 0.5) / (float)HEIGHT) * fov_scale);
}

t_ray generate_ray(t_cam camera, t_view view_params, int x, int y)
{
	t_ray	ray;
	float	view_right[3];
	float	view_up[3];
	float	normalized_x;
	float	normalized_y;
	
	// Ray starts from camera
	vec_copy(ray.origin, camera.xyz);
	normalized_x = screen_x_to_viewport(x,
		view_params.aspect_ratio, view_params.fov_scale);
	normalized_y = screen_y_to_viewport(y, view_params.fov_scale);
	// Compute Ray Direction
	vec_scale(view_right, view_params.cam_right, normalized_x);
	vec_scale(view_up, view_params.cam_up, normalized_y);
	vec_add(ray.direction, view_right, view_up);
	vec_add(ray.direction, ray.direction, camera.vc);
	vec_normalize(ray.direction);
	return (ray);
}
