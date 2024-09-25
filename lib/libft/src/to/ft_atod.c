/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:31:56 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/14 16:07:40 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	skip_space_and_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if ((str[i] && str[i] == '+') || (str[i] && str[i] == '-'))
		i++;
	if (str[i - 1] == '-')
		*sign = -1;
	return (i);
}

double	ft_atod(char *str)
{
	double	nb;
	double	fract;
	int		i;
	int		sign;
	double	power;

	nb = 0;
	sign = 1;
	fract = 0;
	power = 1;
	i = skip_space_and_sign(str, &sign);
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		power /= 10;
		fract = fract + (str[i] - '0') * power;
		i++;
	}
	return ((nb + fract) * sign);
}
