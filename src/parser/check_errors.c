/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:03:26 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/14 19:19:11 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	number_argument(int argc)
{
	if (argc == 1)
	{
		ft_putendl_fd("miniRT requires a single file parameter", 2);
		return (1);
	}
	ft_putendl_fd("miniRT requires only one argument", 2);
	return (1);
}

int	check_errors(int argc, char **argv)
{
	if (argc != 2)
		return (number_argument(argc));
	(void)argv;
	return (0);
}
