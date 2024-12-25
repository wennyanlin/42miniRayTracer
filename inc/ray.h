/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:15:36 by wlin              #+#    #+#             */
/*   Updated: 2024/12/25 23:53:06 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

void	init_mlx(t_data *data);
t_view	init_view_params(t_cam camera);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	render_scene(t_data *data);
t_ray	generate_ray(t_cam camera, t_view view_params, int x, int y);
int		normal_color(float normal[3]);
// int		ray_color(t_ray ray, t_obj obj, double t);

#endif
