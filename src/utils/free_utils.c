/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:49:43 by cle-tron          #+#    #+#             */
/*   Updated: 2024/10/03 13:33:08 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_array(char **array)
{
	char	**tmp;

	tmp = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(tmp);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_data(t_data *data)
{
	t_obj	*tmp;

	if (data->amb)
		free(data->amb);
	if (data->cam)
		free(data->cam);
	if (data->light)
		free(data->light);
	while (data->obj)
	{
		tmp = data->obj;
		data->obj = data->obj->next;
		free(tmp);
	}
	if (data->img->img)
		mlx_destroy_image(data->conn, data->img->img);
	if (data->img)
		free(data->img);
	if (data->win)
		mlx_destroy_window(data->conn, data->win);
	if (data->conn)
		mlx_destroy_display(data->conn);
	free(data->conn);
	free(data);
}
