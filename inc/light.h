/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:39:49 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/24 15:53:48 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

int		color_converter(int obj_rgb[3], double intensity, t_amb *amb);
void	lightning(t_hit_rec *rec, t_data *data);
bool	calc_shadows(t_data *data, t_hit_rec *rec);

#endif
