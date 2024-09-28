/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/28 15:58:10 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	free(data);
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
	free_data(data);
	return (0);
}
