/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:15:36 by wlin              #+#    #+#             */
/*   Updated: 2024/12/10 17:12:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

t_ray	generate_ray(t_cam camera, t_view view_params, int x, int y);
bool	intersect_sphere(t_ray ray, t_obj sphere, double *t);
bool	hit_cylinder(t_ray ray, t_obj cylinder, double *t);
int		color_converter(double color[3]);
int		ray_color(t_ray ray, t_obj obj, double t);
void	ray_at_t(double result[3], t_ray ray, double t);
int		check_caps_hit(t_ray ray, t_obj cy, double *t, int *hit_flag);
int		hit_plane(t_ray ray, t_obj plane, double *t);

//Math Calculation
void	vec_add(double result[3], double a[3], double b[3]);
void	vec_normalize(double v[3]);
void	vec_scale(double result[3], double v[3], double scalar);
void	vec_sub(double result[3], double a[3], double b[3]);
double	vec_dot(double a[3], double b[3]);
void	vec_cross(double result[3], double a[3], double b[3]);
void	vec_copy(double vec_dest[3], double vec_src[3]);
void	vec_project(double *result, double *v, double *axis);
double	vec_length(double vec[3]);
void	vec_div(double vec[3], double scalar);

#endif