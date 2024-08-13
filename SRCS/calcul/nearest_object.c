/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:49:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/25 01:15:00 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "calcul.h"

float	_nearest_plane(float length, t_coord *pos, t_scene *scene,
	t_coord *axis)
{
	float	temp;
	int		k;
	float	limit;

	temp = -1;
	limit = 0.0f;
	if (pos != scene->camera->r_pos)
		limit = 0.01f;
	k = -1;
	while (scene->plane && scene->plane[++k])
	{
		temp = _inter_plane(pos, scene->plane[k], axis);
		if (temp >= limit && (temp < length || length == -1))
		{
			length = temp;
			scene->object = scene->plane[k];
			scene->fct = _intensity_of_plane;
			scene->rgb_object = scene->plane[k]->color;
		}
	}
	return (length);
}

float	_nearest_sphere(float length, t_coord *pos, t_scene *scene,
		t_coord *axis)
{
	float	temp;
	int		k;
	float	limit;

	temp = -1;
	limit = 0.0f;
	if (pos != scene->camera->r_pos)
		limit = 0.01f;
	k = -1;
	while (scene->sphere && scene->sphere[++k])
	{
		temp = _inter_sphere(pos, scene->sphere[k], axis);
		if (temp >= limit && (temp < length || length == -1))
		{
			length = temp;
			scene->object = scene->sphere[k];
			scene->fct = _intensity_of_sphere;
			scene->rgb_object = scene->sphere[k]->color;
		}
	}
	return (length);
}

float	_nearest_cylinder(float length, t_coord *pos, t_scene *scene,
	t_coord *axis)
{
	float	temp;
	int		k;
	float	limit;

	temp = -1;
	limit = 0.0f;
	if (pos != scene->camera->r_pos)
		limit = 0.01f;
	k = -1;
	while (scene->cylinder && scene->cylinder[++k])
	{
		temp = _inter_cylinder(pos, scene->cylinder[k], axis);
		if (temp >= limit && (temp < length || length == -1))
		{
			length = temp;
			scene->object = scene->cylinder[k];
			scene->fct = _intensity_of_cylinder;
			scene->rgb_object = scene->cylinder[k]->color;
		}
	}
	return (length);
}
