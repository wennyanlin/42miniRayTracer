/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:15:36 by wlin              #+#    #+#             */
/*   Updated: 2024/11/24 21:41:53 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

t_ray   generate_ray(t_cam camera, t_view view_params, int x, int y);
int     intersect_sphere(t_ray ray, t_obj sphere, double *t);
int     intersect_cylinder(t_ray ray, t_obj cylinder, double *t);
int     intersect_infinite_plane(t_ray ray, t_obj plane, double *t);
int     color_converter(double color[3]);
int     ray_color(t_ray ray, t_obj obj, double t);
void    ray_at_t(double result[3], t_ray ray, double t);

void    vec_add(double result[3], double a[3], double b[3]);
void    vec_normalize(double v[3]);
void    vec_scale(double result[3], double v[3], double scalar);
void    vec_sub(double result[3], double a[3], double b[3]);
double  vec_dot(double a[3], double b[3]);
void    vec_cross(double result[3], double a[3], double b[3]);
void    vec_copy(double vec_dest[3], double vec_src[3]);

#endif