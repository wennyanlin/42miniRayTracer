/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/10/03 14:46:41 by cle-tron         ###   ########.fr       */
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
	data->win = mlx_new_window(data->conn, 2000, 1500, "miniRT");
	if (!data->win)
		system_error_free_data("mlx_new_window", data);
	data->img->img = mlx_new_image(data->conn, 2000, 1500);
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

void	render(t_data *data)
{
	int	x;
	int	y;

	x = 50;
	while (x < 200)
	{
		y = 50;
		while (y < 200)
		{
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
