/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:21 by cle-tron          #+#    #+#             */
/*   Updated: 2024/11/26 00:49:29 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_ray
{
	double	origin[3];
	double	direction[3];
}	t_ray;

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

typedef struct t_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_img;

typedef struct s_view
{
	double	aspect_ratio;
	double	fov_scale;
	double	cam_right[3];
	double	cam_up[3];
}	t_view;

typedef	struct s_hit
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t0;
	double	t1;
	int		hit_flag;
}	t_hit;


typedef struct s_data
{
	void	*conn;
	void	*win;
	t_img	*img;
	t_amb	*amb;
	t_cam	*cam;
	t_light	*light;
	t_obj	*obj;
	t_view	view_params;
}	t_data;

#endif
