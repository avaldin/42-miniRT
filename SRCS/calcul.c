/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:35 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 17:37:41 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../HDRS/structure.h"
#include "../include/libft/libft.h"

float	_direct_axis(t_scene *scene, int i, int j, int axis)
{
	float	norm;
	float 	fov_angle;

	norm = sqrtf(scene->dov[0] * scene->dov[0]
			+ scene->dov[1] * scene->dov[1] + scene->dov[2] * scene->dov[2]);
	if (axis == 0)
		fov_angle = scene->fov / 2  * (scene->x_screen - i) / scene->x_screen;
	else
		fov_angle =  35  * (scene->y_screen - j) / scene->y_screen;
	return(cosf(fov_angle + acosf(scene->dov[axis] / norm)));
}

float	_eq_sec_deg(float a, float b, float c)
{
	float	result_a;
	float	result_b;

	if (powf(b, 2) - 4 * a * c < 0 || !a)
		return (-1);
	result_a = (-b - sqrtf(powf(b, 2) - 4 * a * c)) / (2 * a);
	result_b = (-b + sqrtf((powf(b, 2) - 4 * a * c))) / (2 * a);
	if ((result_a >= 0 && result_a < result_b) || result_b < 0)
		return (result_a);
	return (result_b);
}
