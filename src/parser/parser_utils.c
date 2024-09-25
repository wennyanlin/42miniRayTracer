/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:00:53 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/13 18:12:29 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	element_id(char *elem)
{
	if (!ft_strncmp(elem, "A", 2))
		return (AMBIENT);
	else if (!ft_strncmp(elem, "C", 2))
		return (CAMERA);
	else if (!ft_strncmp(elem, "L", 2))
		return (LIGHT);
	else if (!ft_strncmp(elem, "sp", 3))
		return (SPHERE);
	else if (!ft_strncmp(elem, "pl", 3))
		return (PLANE);
	else if (!ft_strncmp(elem, "cy", 3))
		return (CYLINDER);
	else
		return (-1);
}
