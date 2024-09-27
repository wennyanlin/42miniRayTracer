/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_range_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:05:42 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/27 17:09:41 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_ratio(char *ratio, char *id)
{
	if (double_syntax(ratio))
		return (print_syntax_error(ratio, "ratio", "double", id), 1);
	if (ft_atod(ratio) < 0 || ft_atod(ratio) > 1)
		return (print_range_error(ratio, "ratio", id, "0.0,1.0"), 1);
	return (0);
}

int	check_rgb(char *arg, char *id)
{
	char	**rgb;
	int		i;

	rgb = ft_split(arg, ',');
	if (array_len(rgb) != 3)
		return (print_array_error(arg, "color", id), free_array(rgb), 1);
	i = 0;
	while (rgb[i])
	{
		if (int_syntax(rgb[i]))
			return (print_syntax_error(rgb[i], "color", "integer", id), \
														free_array(rgb), 1);
		if (ft_strlen(rgb[i]) > 9 || ft_atoi(rgb[i]) < 0 || \
														ft_atoi(rgb[i]) > 255)
			return (print_range_error(rgb[i], "color", id, "0,255"), \
															free_array(rgb), 1);
		i++;
	}
	return (free_array(rgb), 0);
}

int	check_xyz(char *arg, char *id, char *type)
{
	char	**xyz;
	int		i;

	xyz = ft_split(arg, ',');
	if (array_len(xyz) != 3)
		return (print_array_error(arg, type, id), free_array(xyz), 1);
	i = 0;
	while (xyz[i])
	{
		if (double_syntax(xyz[i]))
			return (print_syntax_error(xyz[i], type, "double", id), \
														free_array(xyz), 1);

		i++;
	}
	return (free_array(xyz), 0);
}
