/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:21 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/19 17:30:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_ray
{
	float	origin[3];
	float	direction[3];
}	t_ray;

typedef struct s_amb
{
	int		id;
	float	ratio;
	int		rgb[3];
}	t_amb;

typedef struct s_cam
{
	int		id;
	float	xyz[3];
	float	vc[3];
	int		fov;
}	t_cam;

typedef struct s_light
{
	int		id;
	float	xyz[3];
	float	ratio;
}	t_light;

typedef struct s_obj
{
	int				id;
	float			xyz[3];
	float			vc[3];
	float			diam;
	float			height;
	int				rgb[3];
	struct s_obj	*next;
}	t_obj;

typedef struct s_cap
{
	float	normal[3];
	float	center[3];
	float	radius;
}	t_cap;

typedef struct s_hit_rec
{
	float	p[3];
	float	t;
	float	normal[3];
	float	intensity;
	t_obj	obj;
}	t_hit_rec;

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
	float	aspect_ratio;
	float	fov_scale;
	float	cam_right[3];
	float	cam_up[3];
}	t_view;

typedef struct s_quad
{
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	t1;
	float	t2;
	bool	hit_flag;
}	t_quad;

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
