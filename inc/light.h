/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:39:49 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/20 15:30:38 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

int		color_converter(int color[3], double intensity);
void	lightning(t_hit_rec *rec, t_data *data);




//double	screen_y_to_viewport(int y, double fov_scale);
//double	screen_x_to_viewport(int x, double aspect_ratio, double fov_scale);
#endif
