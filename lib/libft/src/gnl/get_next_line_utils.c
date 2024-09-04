/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:21:38 by ale-tron          #+#    #+#             */
/*   Updated: 2024/02/08 18:41:31 by ale-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = (char *)malloc(sizeof(char) * len);
	if (string == NULL)
		return (free(s1), NULL);
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
	return (free(s1), string);
}

char	*ft_strchr(char *s, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	if (ch == '\0')
		return (s + i);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len * sizeof(*ptr));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	j;
	size_t	size;

	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (len > size)
		len = size;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < start)
		i++;
	j = 0;
	while (s[i + j] && j < len)
	{
		string[j] = s[i + j];
		j++;
	}
	string[j] = '\0';
	return (string);
}
