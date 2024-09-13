/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/13 18:11:11 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_data(t_data *data)
{
	t_obj	*tmp;

	free(data->amb->id);
	free(data->amb);
	free(data->cam->id);
	free(data->cam);
	free(data->light->id);
	free(data->light);
	while (data->obj)
	{
		tmp = data->obj;
		data->obj = data->obj->next;
		free(tmp);
	}
}

int main(int argc, char **argv)
{
	t_data	data;
	(void)argc;
	//check_errors function if(error) return 0;
	init(argv[1], &data);
	print_data(&data);
	free_data(&data);
	return (0);
}
