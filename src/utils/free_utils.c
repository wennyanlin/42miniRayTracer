/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:49:43 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 16:51:26 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_array(char **array)
{
	char **tmp;

	tmp = array;
	while (*array)
	{
		free(*array);
		array++;
	}
	free(tmp);
}
