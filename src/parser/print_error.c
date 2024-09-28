/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:52:44 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/28 15:54:22 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_range_error(char *arg, char *type, char *id, char *range)
{
	ft_putstr_fd("Error: \"", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\" the ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" value in the \"", 2);
	ft_putstr_fd(id, 2);
	ft_putstr_fd("\" parameter should be within the [", 2);
	ft_putstr_fd(range, 2);
	ft_putendl_fd("] range", 2);
}

void	print_array_error(char *arg, char *type, char *id)
{
	ft_putstr_fd("Error: \"", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\" the ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd("s should have 3 values in the \"", 2);
	ft_putstr_fd(id, 2);
	ft_putendl_fd("\" parameter", 2);
}

void	print_syntax_error(char *arg, char *type, char *data, char *id)
{
	ft_putstr_fd("Error: \"", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\" the syntax for the ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" value (", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(") in the \"", 2);
	ft_putstr_fd(id, 2);
	ft_putendl_fd("\" parameter is incorrect", 2);
}

void	print_positive_error(char *arg, char *type, char *id)
{
	ft_putstr_fd("Error: \"", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("\" the ", 2);
	ft_putstr_fd(type, 2);
	ft_putstr_fd(" value in the \"", 2);
	ft_putstr_fd(id, 2);
	ft_putendl_fd("\" parameter must be a positive number", 2);
}
