/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:05 by ale-tron          #+#    #+#             */
/*   Updated: 2024/03/31 15:11:03 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/libft.h"

size_t	count_words(const char *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (str[0] && str[1] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i + 1] == c && str[i] != c)
			count++;
		i++;
	}
	if (i > 1 && str[i - 1] != c && c != 0)
		return (count + 1);
	return (count);
}

int	count_char(const char *str, int j, char c)
{
	int	count;

	count = 0;
	while (str[j] && str[j] != c)
	{
		j++;
		count++;
	}
	return (count);
}

int	make_words(char **result, const char *str, char c, size_t words)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < words)
	{
		k = 0;
		while (str[j] && str[j] == c)
			j++;
		result[i] = malloc(sizeof(char) * (count_char(str, j, c) + 1));
		if (!result[i])
			return (0);
		while (str[j] != c && str[j])
		{
			result[i][k] = str[j];
			k++;
			j++;
		}
		result[i][k] = '\0';
		i++;
	}
	result[i] = NULL;
	return (1);
}

char	**free_tab(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free (result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**result;

	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!make_words(result, s, c, words))
		return (free_tab(result));
	return (result);
}
