/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:14:21 by wlin              #+#    #+#             */
/*   Updated: 2024/12/25 23:31:41 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	screen_x_to_viewport(int x, double aspect_ratio, double fov_scale)
{
	return ((2.0 * (x + 0.5) / (double)WIDTH - 1.0) * aspect_ratio * fov_scale);
}

double	screen_y_to_viewport(int y, double fov_scale)
{
	return ((1.0 - 2.0 * (y + 0.5) / (double)HEIGHT) * fov_scale);
}

t_view	init_view_params(t_cam camera)
{
	static double	world_up[3] = {0.0, 1.0, 0.0}; // Global "up" vector
	t_view				view_params;

	if (fabs(camera.vc[1]) > 0.999)
	{
		world_up[0] = 1.0; // Adjust the "up" vector to avoid instability
		world_up[1] = 0.0;
	}
	view_params.aspect_ratio = (double)WIDTH / (double)HEIGHT;
	view_params.fov_scale = tan((camera.fov * 0.5) * (M_PI / 180.0));  // Convert FOV from degrees to radians and get the scale
	// Calculate Camera Basis Vectors (Right and Up)
	vec_cross(view_params.cam_right, world_up, camera.vc); // Cross product to get cam_right
	vec_normalize(view_params.cam_right);
	vec_cross(view_params.cam_up, camera.vc, view_params.cam_right); // Cross product to get cam_up
	vec_normalize(view_params.cam_up);
	return (view_params);
}

t_ray	generate_ray(t_cam camera, t_view view_params, int x, int y)
{
	t_ray	ray;
	double	view_right[3];
	double	view_up[3];
	double	normalized_x;
	double	normalized_y;

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
