/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:58:55 by wlin              #+#    #+#             */
/*   Updated: 2024/12/25 13:47:02 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	render_pixel(t_data *data, t_hit_rec *rec, int x, int y)
{
	t_obj	*obj;
	t_ray	ray;
	bool	hit_flag;

	hit_flag = false;
	obj = data->obj;
	rec->t = 2147483647;
	while (obj != NULL)
	{
		ray = generate_ray(*(data->cam), data->view_params, x, y);
		if (obj->id == PLANE)
			hit_flag = hit_plane(ray, *(obj), rec);
		else if (obj->id == SPHERE)
			hit_flag = hit_sphere(ray, *(obj), rec);
		else if (obj->id == CYLINDER)
			hit_flag = hit_cylinder(ray, *(obj), rec);
		if (hit_flag)
		{
			lightning(rec, data);
			my_mlx_pixel_put(data->img, x, y,
				color_converter(obj->rgb, rec->intensity, data->amb));
		}
		obj = obj->next;
	}
}

void	render_scene(t_data *data)
{
	int			x;
	int			y;
	t_hit_rec	rec;

	x = 0;
	data->view_params = init_view_params(*(data->cam));
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			render_pixel(data, &rec, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->conn, data->win, data->img->img, 0, 0);
	mlx_loop(data->conn);
}
