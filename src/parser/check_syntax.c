/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:18:34 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/27 15:26:29 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	double_syntax(char *arg)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if ((arg[i] && arg[i] == '+') || (arg[i] && arg[i] == '-'))
		i++;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			point++;
			i++;
			if (point > 1)
				return (1);
		}
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	if (!ft_isdigit(arg[i - 1]))
		return (1);
	return (0);
}

int	int_syntax(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (!ft_isdigit(arg[i + 1]))
				return (1);
			i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
				return (1);
		i++;
	}
	return (0);	
}