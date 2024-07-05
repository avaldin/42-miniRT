/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:03:00 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 18:55:26 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/calcul.h"
#include <math.h>

//float	_inter_plane(t_scene *scene, t_plane *plane, int i, int j)
//{
//
//}

float	_inter_sphere(t_scene *scene, t_sphere *sphere, int i, int j)
{

	float	result_a;
	float	result_b;
	t_coord	*axis;

	axis = _direct_axis(scene, i, j, scene->var);
	if (4 * _sq((scene->camera->pos->x - sphere->pos->x) * axis->z
		+ (scene->camera->pos->y - sphere->pos->y) * axis->y
		+ (scene->camera->pos->z - sphere->pos->z) * axis->z)
		- 4 * (_sq(scene->camera->pos->x - sphere->pos->x)
		+ _sq(scene->camera->pos->y - sphere->pos->y)
		+ _sq(scene->camera->pos->z - sphere->pos->z))
		+ 4 * _sq(sphere->radius) < 0)
		return (-1);
	result_a = -(2 * ((scene->camera->pos->x - sphere->pos->x)* axis->x
			+ (scene->camera->pos->y - sphere->pos->y) * axis->y
			+ (scene->camera->pos->z - sphere->pos->z) * axis->z)
			+ sqrtf(4 * _sq((scene->camera->pos->x - sphere->pos->x)
			* axis->x + (scene->camera->pos->y - sphere->pos->y)
			* axis->y + (scene->camera->pos->z - sphere->pos->z)
			* axis->z) - 4 * (_sq(scene->camera->pos->x - sphere->pos->x)
			+ _sq(scene->camera->pos->y - sphere->pos->y)
			+ _sq(scene->camera->pos->z - sphere->pos->z))
			+ 4 * _sq(sphere->radius))) / 2;
	result_b = -(2 * ((scene->camera->pos->x - sphere->pos->x) * axis->z
			+ (scene->camera->pos->y - sphere->pos->y) * axis->y
			+ (scene->camera->pos->z - sphere->pos->z) * axis->z)
			- sqrtf(4 * _sq((scene->camera->pos->x - sphere->pos->x)
			* axis->x + (scene->camera->pos->y - sphere->pos->y)
			* axis->y + (scene->camera->pos->z - sphere->pos->z)
			* axis->z) - 4 * (_sq(scene->camera->pos->x - sphere->pos->x)
			+ _sq(scene->camera->pos->y - sphere->pos->y)
			+ _sq(scene->camera->pos->z - sphere->pos->z)) + 4
			* _sq(sphere->radius))) / 2;
	if ((result_a >= 0 && result_a < result_b) || result_b < 0)
		return (result_a);
	return (result_b);
}

// void	_inter_cylinder(t_scene *scene, t_cylinder *cylinder, int i, int j)
// {
//
// }