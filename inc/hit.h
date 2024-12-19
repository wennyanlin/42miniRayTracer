/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:39 by cle-tron          #+#    #+#             */
/*   Updated: 2024/12/19 17:30:35 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

bool	hit_plane(t_ray ray, t_obj pl, t_hit_rec *rec);
bool	hit_sphere(t_ray ray, t_obj sp, t_hit_rec *rec);
bool	hit_cylinder(t_ray ray, t_obj cy, t_hit_rec *rec);
bool	check_caps_hit(t_ray ray, t_obj cy, t_hit_rec *rec, bool *hit_flag);
bool	solve_quadratic_t(t_quad quad, float last_closest_t, float *new_t);

//Math Calculation
void	vec_copy(float vec_dest[3], float vec_src[3]);
void	vec_add(float result[3], float a[3], float b[3]);
void	vec_normalize(float v[3]);
void	vec_scale(float result[3], float v[3], float scalar);
void	vec_sub(float result[3], float a[3], float b[3]);
void	vec_div(float vec[3], float scalar);
float	vec_dot(float a[3], float b[3]);
void	vec_cross(float result[3], float a[3], float b[3]);
float	vec_length(float vec[3]);
void	ray_at_t(float result[3], t_ray ray, float t);

#endif