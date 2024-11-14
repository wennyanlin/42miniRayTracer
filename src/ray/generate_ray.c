/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:14:21 by wlin              #+#    #+#             */
/*   Updated: 2024/11/14 11:17:53 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray generate_ray(t_cam camera, int x, int y, int screen_width, int screen_height)
{
    t_ray ray;
    double aspect_ratio;
    double scale;
    // Ray starts from camera
    ray.origin[0] = camera.xyz[0];
    ray.origin[1] = camera.xyz[1];
    ray.origin[2] = camera.xyz[2];
    aspect_ratio = (double)screen_width / (double)screen_height;
    scale = tan((camera.fov * 0.5) * (M_PI / 180.0));  // Convert FOV from degrees to radians and get the scale

    // Calculate Normalized Coordinates for Screen Space
    double normalized_x = (2.0 * (x + 0.5) / (double)screen_width - 1.0) * aspect_ratio * scale;
    double normalized_y = (1.0 - 2.0 * (y + 0.5) / (double)screen_height) * scale;

    // Calculate Camera Basis Vectors (Right and Up)
    double world_up[3] = {0.0, 1.0, 0.0}; // Global "up" vector
    double cam_right[3];
    vec_cross(cam_right, world_up, camera.vc); // Cross product to get cam_right
    vec_normalize(cam_right);

    double cam_up[3];
    vec_cross(cam_up, camera.vc, cam_right); // Cross product to get cam_up
    vec_normalize(cam_up);

    // Compute Ray Direction
    double scaled_right[3], scaled_up[3];
    vec_scale(scaled_right, cam_right, normalized_x);
    vec_scale(scaled_up, cam_up, normalized_y);

    double ray_direction[3];
    vec_add(ray_direction, scaled_right, scaled_up);
    vec_add(ray_direction, ray_direction, camera.vc);
    vec_normalize(ray_direction);

    ray.direction[0] = ray_direction[0];
    ray.direction[1] = ray_direction[1];
    ray.direction[2] = ray_direction[2];

    return ray;
}