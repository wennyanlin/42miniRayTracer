/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:29:23 by wlin              #+#    #+#             */
/*   Updated: 2024/10/18 09:13:33 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void vec_add(double result[3], double a[3], double b[3])
{
    result[0] = a[0] + b[0];
    result[1] = a[1] + b[1];
    result[2] = a[2] + b[2];
}

void vec_normalize(double v[3])
{
    double magnitude = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (magnitude > 0)
    {
        v[0] /= magnitude;
        v[1] /= magnitude;
        v[2] /= magnitude;
    }
}

void vec_sub(double result[3], double a[3], double b[3])
{
    result[0] = a[0] - b[0];
    result[1] = a[1] - b[1];
    result[2] = a[2] - b[2];
}

void vec_scale(double result[3], double v[3], double scalar)
{
    result[0] = v[0] * scalar;
    result[1] = v[1] * scalar;
    result[2] = v[2] * scalar;
}

double vec_dot(double a[3], double b[3])
{
    return (a[0] * b[0] + 
            a[1] * b[1] + 
            a[2] * b[2]);
}

void vec_cross(double result[3], double a[3], double b[3])
{
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

