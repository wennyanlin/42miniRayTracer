/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/11/18 22:20:22 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_win(int keycode, t_data *data)
{
	if (keycode == 0xff1b)
	{
		free_data(data);
		exit(0);
	}
	return (0);
}

int	close_win_x(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	exit(0);
	return (0);
}

void	init_mlx(t_data *data)
{
	data->img = malloc(sizeof(t_img));
	if (!data->img)
		system_error_free_data("malloc", data);
	data->conn = mlx_init();
	if (!data->conn)
		system_error_free_data("mlx_init", data);
	data->win = mlx_new_window(data->conn, WIDTH, HEIGHT, "miniRT");
	if (!data->win)
		system_error_free_data("mlx_new_window", data);
	data->img->img = mlx_new_image(data->conn, WIDTH, HEIGHT);
	if (!data->img->img)
		system_error_free_data("mlx_new_image", data);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp, \
										&data->img->line, &data->img->endian);
	mlx_hook(data->win, 17, 0L, close_win_x, data);
	mlx_hook(data->win, 2, 1L << 0, close_win, data);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line + x * (img->bpp / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

t_view    init_view_params(t_cam camera)
{
	t_view	view_params;
	double world_up[3] = {0.0, 1.0, 0.0}; // Global "up" vector

	view_params.aspect_ratio = (double)WIDTH / (double)HEIGHT;
	view_params.fov_scale = tan((camera.fov * 0.5) * (M_PI / 180.0));  // Convert FOV from degrees to radians and get the scale
	// Calculate Camera Basis Vectors (Right and Up)
	vec_cross(view_params.cam_right, world_up, camera.vc); // Cross product to get cam_right
	vec_normalize(view_params.cam_right);
	vec_cross(view_params.cam_up, camera.vc, view_params.cam_right); // Cross product to get cam_up
	vec_normalize(view_params.cam_up);
	return (view_params);
}

void	render(t_data *data)
{
	int		x;
	int		y;
	t_ray	ray;
	double	t;
	int		bool;

	data->view_params = init_view_params(*(data->cam));
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			ray = generate_ray(*(data->cam), data->view_params, x, y);
			if (data->obj->id == PLANE)
				bool = intersect_infinite_plane(ray, *(data->obj), &t);
			if (data->obj->id == SPHERE)
				bool = intersect_sphere(ray, *(data->obj), &t);
			else if (data->obj->id == CYLINDER)
				bool = intersect_cylinder(ray, *(data->obj), &t);
			if (bool)
				my_mlx_pixel_put(data->img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->conn, data->win, data->img->img, 0, 0);
	mlx_loop(data->conn);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_errors(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		system_error("malloc");
	init(argv[1], data);
	print_data(data);
	init_mlx(data);
	render(data);
	free_data(data);
	return (0);
}
