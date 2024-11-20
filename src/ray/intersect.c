/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:14:15 by wlin              #+#    #+#             */
/*   Updated: 2024/10/14 22:51:26 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int intersect_sphere(t_ray ray, t_obj sphere, double *t)
{
    double  oc[3];
    double  a;
    double  b;
    double  c;
    double discriminant;
    
    vec_sub(oc, ray.origin, sphere.xyz);
    a = vec_dot(ray.direction, ray.direction);
    b = 2.0 * vec_dot(oc, ray.direction);
    c = vec_dot(oc, oc) - (sphere.diam/2) * (sphere.diam/2);
    discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return (0);
    else
    {
        *t = (-b - sqrt(discriminant)) / (2.0 * a);
        return (1);
    }
}
