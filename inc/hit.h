/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:39 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/24 16:40:17 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

bool	hit_plane(t_ray ray, t_obj pl, t_hit_rec *rec);
bool	hit_sphere(t_ray ray, t_obj sp, t_hit_rec *rec);
bool	hit_cylinder(t_ray ray, t_obj cy, t_hit_rec *rec);
bool	check_caps_hit(t_ray ray, t_obj cy, t_hit_rec *rec, bool *hit_flag);
bool	solve_quadratic_t(t_quad quad, double last_closest_t, double *new_t);

//Math Calculation
void	vec_copy(double vec_dest[3], double vec_src[3]);
void	vec_add(double result[3], double a[3], double b[3]);
void	vec_normalize(double v[3]);
void	vec_scale(double result[3], double v[3], double scalar);
void	vec_sub(double result[3], double a[3], double b[3]);
void	vec_div(double vec[3], double scalar);
double	vec_dot(double a[3], double b[3]);
void	vec_cross(double result[3], double a[3], double b[3]);
double	vec_length(double vec[3]);
void	ray_at_t(double result[3], t_ray ray, double t);

#endif