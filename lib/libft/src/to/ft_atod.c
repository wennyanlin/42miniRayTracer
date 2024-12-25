/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:31:56 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/25 23:54:31 by wlin             ###   ########.fr       */
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
	if (i > 0 && str[i - 1] == '-')
		*sign = -1;
	return (i);
}

float	ft_atod(char *str)
{
	float	nb;
	float	fract;
	int		i;
	int		sign;
	float	power;

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
