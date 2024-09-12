/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:00:53 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 16:37:54 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data(t_data *data)
{
	printf("ambient: id:%s, ratio:%f, rgb:%d %d %d\n", data->amb->id, data->amb->ratio, data->amb->rgb[0], data->amb->rgb[1], data->amb->rgb[2]);
}
