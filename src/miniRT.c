/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/24 17:29:45 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_errors(argc, argv))
		return (1);
	data = malloc(sizeof(t_data));
	if (!data)
		system_error("malloc");
	init(argv[1], data);
	print_data(data);
	init_mlx(data);
	render_scene(data);
	free_data(data);
	return (0);
}
