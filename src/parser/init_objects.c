/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:10:18 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/14 18:28:51 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	init_sphere(char **elem, t_obj *node)
{
	node->id = SPHERE;
	fill_coordinates(elem[1], node->xyz);
	node->diam = ft_atod(elem[2]);
	fill_rgb(elem[3], node->rgb);
}

static void	init_plane(char **elem, t_obj *node)
{
	node->id = PLANE;
	fill_coordinates(elem[1], node->xyz);
	fill_coordinates(elem[2], node->vc);
	fill_rgb(elem[3], node->rgb);
}

static void	init_cylinder(char **elem, t_obj *node)
{
	node->id = CYLINDER;
	fill_coordinates(elem[1], node->xyz);
	fill_coordinates(elem[2], node->vc);
	node->diam = ft_atod(elem[3]);
	node->height = ft_atod(elem[4]);
	fill_rgb(elem[5], node->rgb);
}

void	init_objects(char **elem, t_obj **obj, t_data *data)
{
	t_obj	*tmp;
	t_obj	*node;

	node = malloc(sizeof(t_obj));
	if (!node)
		system_error_free_data("malloc", data);
	node->next = NULL;
	if (element_id(elem[0]) == SPHERE)
		init_sphere(elem, node);
	else if (element_id(elem[0]) == PLANE)
		init_plane(elem, node);
	else if (element_id(elem[0]) == CYLINDER)
		init_cylinder(elem, node);
	if (!(*obj))
	{
		*obj = node;
		return ;
	}
	tmp = *obj;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
