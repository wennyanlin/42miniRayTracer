/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:39:49 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/25 23:52:04 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

int		color_converter(int obj_rgb[3], float intensity, t_amb *amb);
void	lightning(t_hit_rec *rec, t_data *data);
bool	calc_shadows(t_data *data, t_hit_rec *rec);

#endif
