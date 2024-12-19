/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:05:40 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/19 17:30:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_rgb(char *color, int *rgb)
{
	char	**rgb_array;
	int		i;

	rgb_array = ft_split(color, ',');
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(rgb_array[i]);
		free(rgb_array[i++]);
	}
	free(rgb_array);
}

void	fill_coordinates(char *coordinates, float *xyz)
{
	char	**xyz_array;
	int		i;

	xyz_array = ft_split(coordinates, ',');
	i = 0;
	while (i < 3)
	{
		xyz[i] = ft_atod(xyz_array[i]);
		free(xyz_array[i++]);
	}
	free(xyz_array);
}
