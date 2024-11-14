/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:15:36 by wlin              #+#    #+#             */
/*   Updated: 2024/10/18 09:16:20 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

t_ray   generate_ray(t_cam camera, int x, int y, int screen_width, int screen_height);
int     intersect_sphere(t_ray ray, t_obj sphere, double *t);


void    vec_add(double result[3], double a[3], double b[3]);
void    vec_normalize(double v[3]);
void    vec_scale(double result[3], double v[3], double scalar);
void    vec_sub(double result[3], double a[3], double b[3]);
double  vec_dot(double a[3], double b[3]);
void    vec_cross(double result[3], double a[3], double b[3]);

#endif