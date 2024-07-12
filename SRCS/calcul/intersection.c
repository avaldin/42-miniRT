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

float	_inter_plane(t_scene *scene, t_plane *plane, t_coord *axis)
{
	if ((plane->vect->x * scene->camera->pos->x
		+ plane->vect->y * scene->camera->pos->y
		+ plane->vect->z * scene->camera->pos->z) <= 0)
		return (-1);
	return ((plane->vect->x * plane->pos->x + plane->vect->y * plane->pos->y
		+ plane->vect->z * plane->pos->z - axis->x - axis->y - axis->z)
		/ (plane->vect->x * scene->camera->pos->x
		+ plane->vect->y * scene->camera->pos->y
		+ plane->vect->z * scene->camera->pos->z));
}

float	_inter_sphere(t_scene *scene, t_sphere *sphere, t_coord *axis)
{
	float	result_a;
	float	result_b;

	if (4 * _sq((scene->camera->pos->x - sphere->pos->x) * axis->x
		+ (scene->camera->pos->y - sphere->pos->y) * axis->y
		+ (scene->camera->pos->z - sphere->pos->z) * axis->z)
		- 4 * (_sq(scene->camera->pos->x - sphere->pos->x)
		+ _sq(scene->camera->pos->y - sphere->pos->y)
		+ _sq(scene->camera->pos->z - sphere->pos->z))
		+ 4 * _sq(sphere->radius) < 0)
		return (-1);
	result_a = -(2 * ((scene->camera->pos->x - sphere->pos->x) * axis->x
			+ (scene->camera->pos->y - sphere->pos->y) * axis->y
			+ (scene->camera->pos->z - sphere->pos->z) * axis->z)
			+ sqrtf(4 * _sq((scene->camera->pos->x - sphere->pos->x)
			* axis->x + (scene->camera->pos->y - sphere->pos->y)
			* axis->y + (scene->camera->pos->z - sphere->pos->z)
			* axis->z) - 4 * (_sq(scene->camera->pos->x - sphere->pos->x)
			+ _sq(scene->camera->pos->y - sphere->pos->y)
			+ _sq(scene->camera->pos->z - sphere->pos->z))
			+ 4 * _sq(sphere->radius))) / 2;
	result_b = -(2 * ((scene->camera->pos->x - sphere->pos->x) * axis->x
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
