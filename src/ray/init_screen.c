/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:26:06 by wlin              #+#    #+#             */
/*   Updated: 2024/12/24 17:28:46 by wlin             ###   ########.fr       */
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
