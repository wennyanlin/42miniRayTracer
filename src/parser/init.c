/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:14 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/26 18:02:11 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init(char *file, t_data *data)
{
	char	**line;
	char	**elem;
	int		i;

	line = copy_elements(file);
	i = 0;
	data->obj = NULL;
	while (line[i])
	{
		printf("%s\n", line[i]); ///BORRAR
		elem = ft_split(line[i], ' ');
		if (element_id(elem[0]) == AMBIENT)
			init_ambient(elem, data);
		else if (element_id(elem[0]) == CAMERA)
			init_camera(elem, data);
		else if (element_id(elem[0]) == LIGHT)
			init_light(elem, data);
		else if (element_id(elem[0]) >= SPHERE)
			init_objects(elem, &data->obj, data);
		free_array(elem);
		free(line[i++]);
	}
	free(line);
}
