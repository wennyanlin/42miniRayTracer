/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:44:07 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/30 12:11:01 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//PRINT
void	print_data(t_data *data);

//FREE_UTILS
void	free_array(char **array);
int		array_len(char **array);
void	free_data(t_data *data);

//SYSTEM_ERROR
void	system_error_free_data(char *str, t_data *data);
void	system_error(char *str);

#endif
