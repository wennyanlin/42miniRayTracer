/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:33:19 by cle-tron          #+#    #+#             */
/*   Updated: 2024/10/03 14:48:16 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	line_element_id(char *elem)
{
	if (!ft_strncmp(elem, "A ", 2))
		return (AMBIENT);
	else if (!ft_strncmp(elem, "C ", 2))
		return (CAMERA);
	else if (!ft_strncmp(elem, "L ", 2))
		return (LIGHT);
	else if (!ft_strncmp(elem, "sp ", 3))
		return (SPHERE);
	else if (!ft_strncmp(elem, "pl ", 3))
		return (PLANE);
	else if (!ft_strncmp(elem, "cy ", 3))
		return (CYLINDER);
	else
		return (-1);
}

void	print_invalid_id(char *line)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = ft_strtrim(line, " ");
	while (tmp[len] != '\0' && tmp[len] != ' ')
		len++;
	ft_putstr_fd("Error: ", 2);
	write(2, tmp, len);
	ft_putendl_fd(": invalid identifier", 2);
	free(tmp);
}

void	print_error_id(int num, char *id)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(id, 2);
	if (num > 1)
		ft_putendl_fd(" identifier can only be declared once", 2);
	else if (num == 0)
		ft_putendl_fd(" identifier must be declared", 2);
}

int	check_invalid_id(int (*count)[4], char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (line_element_id(tmp) == AMBIENT)
		(*count)[0] += 1;
	else if (line_element_id(tmp) == CAMERA)
		(*count)[1] += 1;
	else if (line_element_id(tmp) == LIGHT)
		(*count)[2] += 1;
	else if (line_element_id(tmp) >= SPHERE)
		(*count)[3] += 1;
	else if (line_element_id(tmp) == -1)
		return (free(tmp), 1);
	return (free(tmp), 0);
}

int	check_identifiers(char **line)
{
	int		count[4];
	int		i;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	while (line[i])
	{
		if (check_invalid_id(&count, line[i]))
			return (print_invalid_id(line[i]), 1);
		i++;
	}
	if (count[0] != 1)
		return (print_error_id(count[0], "ambient A"), 1);
	if (count[1] != 1)
		return (print_error_id(count[1], "camera C"), 1);
	if (count[2] != 1)
		return (print_error_id(count[2], "light L"), 1);
	if (count[3] == 0)
		return (ft_putendl_fd("Error: you must declare at least one object", \
																	2), 1);
	return (0);
}
