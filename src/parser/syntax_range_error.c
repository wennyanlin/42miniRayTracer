/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_range_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:05:42 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/26 00:00:48 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_ratio(char *ratio, char *id)
{
	if (float_syntax(ratio))
		return (print_syntax_error(ratio, "ratio", "float", id), 1);
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
		{
			print_syntax_error(rgb[i], "color", "integer", id);
			return (free_array(rgb), 1);
		}
		if (ft_strlen(rgb[i]) > 9 || ft_atoi(rgb[i]) < 0 || \
														ft_atoi(rgb[i]) > 255)
		{
			print_range_error(rgb[i], "color", id, "0,255");
			return (free_array(rgb), 1);
		}
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
		if (float_syntax(xyz[i]))
		{
			print_syntax_error(xyz[i], type, "float", id);
			return (free_array(xyz), 1);
		}
		if (ft_strncmp(type, "vector", 7) == 0)
		{
			if (ft_atod(xyz[i]) < -1 || ft_atod(xyz[i]) > 1)
			{
				print_range_error(xyz[i], type, id, "-1,1");
				return (free_array(xyz), 1);
			}
		}
		i++;
	}
	return (free_array(xyz), 0);
}

int	check_measure(char *arg, char *id, char *type)
{
	if (float_syntax(arg))
		return (print_syntax_error(arg, type, "float", id), 1);
	if (ft_atod(arg) <= 0)
		return (print_positive_error(arg, type, id), 1);
	return (0);
}
