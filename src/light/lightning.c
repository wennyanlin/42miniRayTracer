/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:54:12 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/24 18:03:28 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	calc_color(int obj_color, int amb_color, double intensity, double amb_ratio)
{
	int	base;
	int	ambient;
	int	result;

	base = (int)(obj_color * intensity * (1 - amb_ratio));
	ambient = (int)(obj_color / 255 * amb_color * amb_ratio);
	result = base + ambient;
	if (result > 255)
		result = 255;
	return (result);
}

int	color_converter(int obj_rgb[3], double intensity, t_amb *amb)
{
	int	r;
	int	g;
	int	b;

	r = calc_color(obj_rgb[0], amb->rgb[0], intensity, amb->ratio);
	g = calc_color(obj_rgb[1], amb->rgb[1], intensity, amb->ratio);
	b = calc_color(obj_rgb[2], amb->rgb[2], intensity, amb->ratio);
	return ((r << 16) | (g << 8) | b);
}

double	lambert_law(double light_dir[3], double norm[3])
{
	double	intensity;

	intensity = vec_dot(light_dir, norm);
	if (intensity < 0)
		intensity = 0;
	return (intensity);
}

void	lightning(t_hit_rec *rec, t_data *data)
{
	double	light_dir[3];

	vec_sub(light_dir, data->light->xyz, rec->p);
	vec_normalize(light_dir);
	if (calc_shadows(data, rec))
		rec->intensity = data->amb->ratio;
	else
	{
		rec->intensity = lambert_law(light_dir, rec->normal) * \
		data->light->ratio + data->amb->ratio;
	}
	if (rec->intensity > 1)
		rec->intensity = 1;
}
