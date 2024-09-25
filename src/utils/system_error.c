/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:45:09 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/14 18:31:20 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	system_error_free_data(char *str, t_data *data)
{
	write(2, "error: ", 7);
	perror(str);
	if (data)
		free_data(data);
	exit(errno);
}

void	system_error(char *str)
{
	write(2, "error: ", 7);
	perror(str);
	exit(errno);
}
