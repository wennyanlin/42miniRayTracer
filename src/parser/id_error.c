/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:33:19 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/15 14:48:47 by cle-tron         ###   ########.fr       */
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

void	print_invalid_id(char *tmp)
{
	int len;

	len = 0;
	while (tmp[len] != ' ')
		len++;
	ft_putstr_fd("Error: ",2);
	write(2, tmp, len);
	ft_putendl_fd(": invalid identifier", 2);

}

int	check_identifiers(char **line)
{
	int		a;
	int		c;
	int		l;
	int		obj;
	int		i;
	char	*tmp;

	i = 0;
	a = 0;
	c = 0;
	l = 0;
	obj = 0;
//	printf("%p\n", line[i]);
	while (line[i])
	{
//	printf("%s", line[i]);
		tmp = ft_strtrim(line[i], " ");
//		printf("%s", tmp);
		if (line_element_id(tmp) == AMBIENT)
			a++;
		else if (line_element_id(tmp) == CAMERA)
			c++;
		else if (line_element_id(tmp) == LIGHT)
			l++;
		else if (line_element_id(tmp) >= SPHERE)
			obj++;
		else if (line_element_id(tmp) == -1)
			return (print_invalid_id (tmp), 1);
		i++;
		free(tmp);
	}
	
	return (0);
}

