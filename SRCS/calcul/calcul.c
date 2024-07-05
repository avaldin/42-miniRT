/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:35 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/07 00:14:34 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structure.h"
#include "libft.h"
#include "calcul.h"

float	*_matrix_var(t_scene *scene)
{
	float	*var;

	var = ft_calloc(4, sizeof(float));
	if (!var)
		exit(50); // pas ok
	if (!scene->camera->vect->z && !scene->camera->vect->x)
	{
		var[0] = 0;
		var[1] = 1;
	}
	else
	{
		var[0] = 1 / sqrtf(1
				+ _sq(scene->camera->vect->y) / (_sq(scene->camera->vect->x)
				+ _sq(scene->camera->vect->z)));
		var[1] = scene->camera->vect->y / (_sq(scene->camera->vect->x)
				+ _sq(scene->camera->vect->y) + _sq(scene->camera->vect->z));
	}
	if (!scene->camera->vect->z && scene->camera->vect->x)
	{
		var[2] = 0;
		var[3] = 1;
		if (scene->camera->vect->x < 0)
			var[3] = -1;
	}
	else if (!scene->camera->vect->z && !scene->camera->vect->x)
	{
		var[2] = 1;
		var[3] = 0;
	}
	else
	{
		var[2] = 1 / sqrtf(1
				+ _sq(scene->camera->vect->x) / _sq(scene->camera->vect->z));
		var[3] = (scene->camera->vect->x / scene->camera->vect->z) / sqrtf(1
				+ _sq(scene->camera->vect->x) / _sq(scene->camera->vect->z));
	}
	scene->var = var;
	return (var);
}

//void	_dov(t_scene *scene, float *var)
//{
//	scene->dov_x[0] = var[2];
//	scene->dov_x[1] = 0;
//	scene->dov_x[2] = -var[3];
//	scene->dov_y[0] = var[1] * var[3];
//	scene->dov_y[1] = var[0];
//	scene->dov_y[2] = var[1] * var[2];
	//printf("xx = %lf")
//}

t_coord	*_direct_axis(t_scene *scene, int i, int j, float *var)
{
	float	temp[3];
	float	axis_angle[3];

	temp[0] = sinf((0.0087266462599f * scene->camera->fov)
			* (float)(2 * i - scene->x_screen) / (float)scene->x_screen)
					* ((float)scene->x_screen / (float)scene->y_screen);
	temp[1] = sinf(0.6108652381980f
			* (float)(2 * j - scene->y_screen) / (float)scene->y_screen);
	//temp[2] = sqrtf(1.0f - _sq(temp[1]) - _sq(temp[0]));
	axis_angle[0] = temp[0] * var[2] + scene->camera->vect->x;
	axis_angle[1] = var[0] * temp[1] + var[1] * temp[0] * var[3]
			+ scene->camera->vect->y;
	axis_angle[2] = var[0] * temp[0] * var[3] - temp[1] * var[1]
			+ scene->camera->vect->z;
	temp[0] = sqrtf(_sq(axis_angle[0]) + _sq(axis_angle[1])
			+ _sq(axis_angle[2]));
	scene->axis->x = axis_angle[0] / temp[0];
	scene->axis->y = axis_angle[1] / temp[0];
	scene->axis->z = axis_angle[2] / temp[0];
 	return (scene->axis);
}

float	_sq(float x)
{
	return (x * x);
}
