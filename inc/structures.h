/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:21 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/11 17:41:51 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_amb
{
	char	*id;
	double	ratio;
	int		rgb[3];
}	t_amb;

typedef struct s_cam
{
	char	*id;
	double	xyz[3];
	double	vc[3];
	int		fov;
}	t_cam;

typedef struct s_light
{
	char	*id;
	double	xyz[3];
	double	ratio;
}	t_light;

typedef struct s_sp
{
	char	*id;
	double	xyz[3];
	double	diam;
	int		rgb[3];
}	t_sp;

typedef struct s_pl
{
	char	*id;
	double	xyz[3];
	double	vc[3];
	int		rgb[3];
}	t_pl;

typedef struct s_cy
{
	char	*id;
	double	xyz[3];
	double	vc[3];
	double	diam;
	double	height;
	int		rgb[3];
}	t_cy;

typedef struct s_obj
{
	void	*obj;
	void	*next;
}	t_obj;

typedef struct s_data
{
	t_amb	*amb;
	t_cam	*cam;
	t_light	*light;
	t_obj	*obj;
}	t_data;

#endif
