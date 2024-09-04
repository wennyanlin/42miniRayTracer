/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:11:02 by ale-tron          #+#    #+#             */
/*   Updated: 2024/03/30 15:02:12 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *)malloc(sizeof(char) * len);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		string[i + j] = s2[j];
		j++;
	}
	string [i + j] = '\0';
	return (string);
}
