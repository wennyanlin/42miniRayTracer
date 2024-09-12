/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:51:08 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 17:40:12 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//INIT
void	init(char *file, t_data *data);

//INIT_ELEMENTS
void	init_ambient(char **elem, t_data *data);
void	init_camera(char **elem, t_data *data);
void	init_light(char **elem, t_data *data);

//FILL
void	fill_rgb(char *color, int *rgb);
void	fill_coordinates(char *coordinates, double *xyz);

#endif
