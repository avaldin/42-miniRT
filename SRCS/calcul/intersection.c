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

#include <libft.h>
#include "../HDRS/structure.h"
#include "../HDRS/calcul.h"
#include <math.h>

t_coord	_intersection_on_line(t_coord *pos, t_coord *axis, float length)
{
	t_coord	intersection;

	intersection.x = pos->x + axis->x * length;
	intersection.y = pos->y + axis->y * length;
	intersection.z = pos->z + axis->z * length;
	return (intersection);
}

float	_inter_plane(t_scene *scene, t_plane *plane, t_coord *axis)
{
	plane->cst = -(plane->vect->x * plane->pos->x + plane->vect->y * plane->pos->y
		+ plane->vect->z * plane->pos->z);
	if ((plane->vect->x * axis->x
		+ plane->vect->y * axis->y
		+ plane->vect->z * axis->z) == 0)
		return (-1);
	return (-(plane->vect->x * scene->camera->pos->x + plane->vect->y * scene->camera->pos->y
		+ plane->vect->z * scene->camera->pos->z + plane->cst)
		/ (plane->vect->x * axis->x
		+ plane->vect->y * axis->y
		+ plane->vect->z * axis->z));
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

float	_inter_disk(t_cylinder *cylinder, t_coord *axis, t_coord *cam_pos, float height)
{
	float	length;
	t_coord	pos;
	t_coord	intersection;

	if ((cylinder->vect->x * axis->x
		+ cylinder->vect->y * axis->y
		+ cylinder->vect->z * axis->z) == 0)
		return (-1);
	pos.x = cylinder->pos->x * height;
	pos.y = cylinder->pos->y * height;
	pos.z = cylinder->pos->z * height;
	length = -(cylinder->vect->x * cam_pos->x + cylinder->vect->y * cam_pos->y
		+ cylinder->vect->z * cam_pos->z - (cylinder->vect->x * pos.x
		+ cylinder->vect->y * pos.y + cylinder->vect->z * pos.z))
		/ (cylinder->vect->x * axis->x + cylinder->vect->y * axis->y
		+ cylinder->vect->z * axis->z);
	intersection = _intersection_on_line(cam_pos, axis, length);
	if (sqrt(_sq(_sq(intersection.x - pos.x) + _sq(intersection.y - pos.y) + _sq(intersection.z - pos.z))) <= _sq(cylinder->radius))
		return (length);
	else
		return (-1);
}

float	_inter_cylinder(t_scene *scene, t_cylinder *cylinder, t_coord *axis)
{
	float	eq_var[3];
	float	discriminant;
	float	result[5];
	int		i;

	result[4] = -1;
	eq_var[0] = _sq(axis->x) + _sq(axis->y) + _sq(axis->z) - _sq(cylinder->vect->x * axis->x + cylinder->vect->y * axis->y +cylinder->vect->z * axis->z);
	eq_var[1] = 2.0f * (axis->x * (scene->camera->pos->x - cylinder->pos->x) + axis->y * (scene->camera->pos->y - cylinder->pos->y) + axis->z * (scene->camera->pos->z - cylinder->pos->z) - (cylinder->vect->x * axis->x + cylinder->vect->y * axis->y + cylinder->vect->z * axis->z) * (cylinder->vect->x * (scene->camera->pos->x - cylinder->pos->x) + cylinder->vect->y * (scene->camera->pos->y - cylinder->pos->y) + cylinder->vect->z * (scene->camera->pos->z - cylinder->pos->z)));
	eq_var[2] = _sq(scene->camera->pos->x - cylinder->pos->x) + _sq(scene->camera->pos->y - cylinder->pos->y) + _sq(scene->camera->pos->z - cylinder->pos->z) - _sq(axis->x * (scene->camera->pos->x - cylinder->pos->x) + axis->y * (scene->camera->pos->y - cylinder->pos->y) + axis->z * (scene->camera->pos->z - cylinder->pos->z)) - _sq(cylinder->radius);
	discriminant = _sq(eq_var[1]) - 4.0f * eq_var[0] * eq_var[2];
	result[0] = -1;
	result[1] = -1;
	if (discriminant >= 0)
	{
		result[0] = (-eq_var[1] - sqrtf(discriminant)) / (2.0f * eq_var[0]);
		if (sqrtf(_sq(_projection(_intersection_on_line(scene->camera->pos, axis, result[0]), cylinder->pos, cylinder->vect))) > cylinder->radius / 2.0f)
			result[0] = -1;
		result[1] = (-eq_var[1] + sqrtf(discriminant)) / (2.0f * eq_var[0]);
		if (sqrtf(_sq(_projection(_intersection_on_line(scene->camera->pos, axis, result[1]), cylinder->pos, cylinder->vect))) > cylinder->radius / 2.0f)
			result[1] = -1;
	}
	result[2] = _inter_disk(cylinder, axis, scene->camera->pos, cylinder->height / 2.0f);
	result[3] = _inter_disk(cylinder, axis, scene->camera->pos, -cylinder->height / 2.0f);
	i = -1;
	while (++i < 4)
	{
		if ((result[i] < result[4] || result[4] == -1) && result[i] >= 0)
		{
			printf("length = %f, i res = %f, i = %d\n", result[4], result[i], i);
			result[4] = result[i];
			cylinder->part = i;
		}
		i++;
	}
	return (result[4]);
}

