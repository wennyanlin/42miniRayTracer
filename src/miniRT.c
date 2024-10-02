/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/10/02 19:18:43 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"



int	close_win(int keycode, t_data *data)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(data->conn, data->win);
		mlx_destroy_display(data->conn);
		free(data->conn);
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
	data->conn = mlx_init();
	data->win = mlx_new_window(data->conn, 1920, 1080, "miniRT");
	mlx_hook(data->win, 17, 0L, close_win_x, data);
	mlx_hook(data->win, 2, 1L << 0, close_win, data);
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
	free_data(data);
	return (0);
}
