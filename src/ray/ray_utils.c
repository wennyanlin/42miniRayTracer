/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:42:57 by wlin              #+#    #+#             */
/*   Updated: 2024/11/24 21:13:55 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void    vec_copy(double vec_dest[3], double vec_src[3])
{
    vec_dest[0] = vec_src[0];
    vec_dest[1] = vec_src[1];
    vec_dest[2] = vec_src[2];
}

int    color_converter(double color[3])
{
    
    int r = (int)(255.999 * color[0]);
    int g = (int)(255.999 * color[1]);
    int b = (int)(255.999 * color[2]);
    return (r << 16) | (g << 8) | b;
}