/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:21 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/30 13:17:50 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_amb
{
	int		id;
	double	ratio;
	int		rgb[3];
}	t_amb;

typedef struct s_cam
{
	int		id;
	double	xyz[3];
	double	vc[3];
	int		fov;
}	t_cam;

typedef struct s_light
{
	int		id;
	double	xyz[3];
	double	ratio;
}	t_light;

typedef struct s_obj
{
	int				id;
	double			xyz[3];
	double			vc[3];
	double			diam;
	double			height;
	int				rgb[3];
	struct s_obj	*next;
}	t_obj;

typedef struct s_data
{
	void	*conn;
	void	*win;
	t_amb	*amb;
	t_cam	*cam;
	t_light	*light;
	t_obj	*obj;
}	t_data;

#endif
