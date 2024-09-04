/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:27:00 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/08 18:39:09 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/libft.h"

size_t	count_size(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count += 1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*zero_case(char *string)
{
	string[0] = 0 + '0';
	return (string);
}

char	*fill_str(char *string, int n, size_t i)
{
	while (i > 0)
	{
		i--;
		string[i] = n % 10 + '0';
		n /= 10;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	size;
	size_t	i;

	size = count_size(n);
	string = malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	string[size] = '\0';
	if (n == 0)
		return (zero_case(string));
	i = size;
	if (n == -2147483648)
	{
		string[size - 1] = '8';
		n = 214748364;
		i = size - 1;
	}
	if (n < 0)
		n = -n;
	fill_str(string, n, i);
	if (string[0] == '0')
		string[0] = '-';
	return (string);
}
