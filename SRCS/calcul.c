/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:35 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/21 15:03:31 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../HDRS/structure.h"
#include "../include/libft/libft.h"

// si dov_z = 0 0 1, dov x y z = 1 1 1;

float	*_matrix_var(t_scene *scene)
{
	float	*var;

	var = ft_calloc(4, sizeof(float));
	if (!var)
		exit(50); // pas ok
	var[0] = powf(scene->dov_z[1], 2)
			/ sqrtf(powf(scene->dov_z[1], 2) + powf(scene->dov_z[1], 2));
	var[1] = powf(scene->dov_z[0], 2)
			 / sqrtf(powf(scene->dov_z[0], 2) + powf(scene->dov_z[1], 2));
	var[2] = scene->dov_z[2];
	var[3] = sqrtf(powf(scene->dov_z[1], 2) + powf(scene->dov_z[1], 2));
	return (var);
}

void	_dov(t_scene *scene, float *var)
{
	scene->dov_x[0] = var[2];
	scene->dov_x[1] = 0;
	scene->dov_x[2] = -var[3];
	scene->dov_y[0] = var[1] * var[3];
	scene->dov_y[1] = var[0];
	scene->dov_y[2] = var[1] * var[2];
	free(var);
}

float	_direct_axis(t_scene *scene, int i, int j, int axis)
{
	float 	fov_angle;

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
