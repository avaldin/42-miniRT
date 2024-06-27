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
	if (!scene->dov_z[2] && !scene->dov_z[1])
	{
		var[0] = 1;
		var[1] = 0;
	}
	else
	{
		var[0] = powf(scene->dov_z[1], 2)
				 / sqrtf(powf(scene->dov_z[1], 2) + powf(scene->dov_z[2], 2));
		var[1] = -powf(scene->dov_z[2], 2)
				 / sqrtf(powf(scene->dov_z[1], 2) + powf(scene->dov_z[2], 2));
	}
	if (!scene->dov_z[2] && !scene->dov_z[0])
	{
		var[2] = 1;
		var[3] = 0;
	}
	else
	{
		var[2] = powf(scene->dov_z[2], 2)
				 / sqrtf(powf(scene->dov_z[0], 2) + powf(scene->dov_z[2], 2));
		var[3] = powf(scene->dov_z[0], 2)
				 / sqrtf(powf(scene->dov_z[0], 2) + powf(scene->dov_z[2], 2));
	}
	scene->var = var;
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
}

float	*_direct_axis(t_scene *scene, int i, int j, float *var)
{
	float 	fov_angle;
	float	temp[3];
	float	*axis_angle;

	axis_angle = ft_calloc(3, sizeof(float));
	if (!axis_angle)
		exit(50); //pas ok
	fov_angle = scene->fov / 2  * (scene->x_screen - 2 * i) / scene->x_screen;
	temp[0] = sinf(fov_angle * 3.141592 / 180);
	fov_angle = 35  * (scene->y_screen - 2 * j) / scene->y_screen;
	temp[1] = sinf(fov_angle * 3.141592 / 180);
	temp[2] = 1 - powf(temp[1], 2) - powf(temp[0], 2);
	axis_angle[0] = temp[0] * var[2] - temp[2] * var[3];
	axis_angle[1] = var[0] * temp[2] + var[1] * (temp[0] * var[3]
			+ temp[3] * var[2]);
	axis_angle[2] = var[0] * (temp[0] * var[3] + temp[2] * var[2])
			- temp[2] * var[2];
	return (axis_angle);
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
