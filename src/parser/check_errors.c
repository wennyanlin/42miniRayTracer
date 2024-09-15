/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:03:26 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/15 14:26:13 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	number_argument(int argc)
{
	if (argc == 1)
		ft_putendl_fd("Error: miniRT requires a single file parameter", 2);
	else
		ft_putendl_fd("Error: miniRT requires only one argument", 2);
	return (1);
}

int	check_extention(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	arg = (arg + len - 3);
	if (ft_strncmp(arg, ".rt", 4))
	{
		ft_putendl_fd("Error: miniRT requires a '.rt' file extention", 2);
		return (1);
	}
	return (0);
}

void	test(char ***line)
{
	int i = 0;
	printf("%p", *line);
	while ((*line)[i])
	{
		printf("%s", (*line)[i]);
		i++;
	}


}


int	check_errors(int argc, char **argv)
{
	char	**line;

	if (argc != 2)
		return (number_argument(argc));
	if (check_extention(argv[1]))
		return (1);
	line = copy_elements(argv[1]);
	if (!line)
		return (ft_putendl_fd("Error: empty file", 2), 1);
//	printf("%p\n", line);
//	printf("%p\n", *line);
//	test(&line);
	if (check_identifiers(line))
		return (free_array(line), 1);
	free(line);
	return (0);
}
