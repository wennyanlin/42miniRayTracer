/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:51:08 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/24 16:40:17 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//CHECK_ERRORS
int		check_errors(int argc, char **argv);

//ID_ERROR
int		check_identifiers(char **line);

//SPECIFIC_DATA_ERROR
int		check_specific_data(char **line);

//OBJECT_ERROR
int		sphere_error(char **elem);
int		plane_error(char **elem);
int		cylinder_error(char **elem);

//SYNTAX_RANGE_ERROR
int		check_ratio(char *ratio, char *id);
int		check_rgb(char *arg, char *id);
int		check_xyz(char *arg, char *id, char *type);
int		check_measure(char *arg, char *id, char *type);

//PRINT_ERROR
void	print_range_error(char *arg, char *type, char *id, char *range);
void	print_array_error(char *arg, char *type, char *id);
void	print_syntax_error(char *arg, char *type, char *data, char *id);
void	print_positive_error(char *arg, char *type, char *id);

//CHECK_SYNTAX
int		double_syntax(char *arg);
int		int_syntax(char *arg);

//INIT
void	init(char *file, t_data *data);

//FILL_DATA
void	fill_rgb(char *color, int *rgb);
void	fill_coordinates(char *coordinates, double *xyz);

//INIT_OBJECTS
void	init_objects(char **elem, t_obj **obj, t_data *data);

//PARSER_UTILS
int		element_id(char *elem);
char	**copy_elements(char *file);

#endif
