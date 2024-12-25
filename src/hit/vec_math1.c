/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlin <wlin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:29:23 by wlin              #+#    #+#             */
/*   Updated: 2024/12/25 23:58:34 by wlin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	vec_add(float result[3], float a[3], float b[3])
{
	result[0] = a[0] + b[0];
	result[1] = a[1] + b[1];
	result[2] = a[2] + b[2];
}

/*Va - Vb => Va + (-Vb)*/
void	vec_sub(float result[3], float a[3], float b[3])
{
	result[0] = a[0] - b[0];
	result[1] = a[1] - b[1];
	result[2] = a[2] - b[2];
}

void	vec_scale(float result[3], float vec[3], float scalar)
{
	result[0] = vec[0] * scalar;
	result[1] = vec[1] * scalar;
	result[2] = vec[2] * scalar;
}

void	vec_div(float vec[3], float scalar)
{
	vec[0] /= scalar;
	vec[1] /= scalar;
	vec[2] /= scalar;
}

void	vec_copy(float vec_dest[3], float vec_src[3])
{
	vec_dest[0] = vec_src[0];
	vec_dest[1] = vec_src[1];
	vec_dest[2] = vec_src[2];
}
