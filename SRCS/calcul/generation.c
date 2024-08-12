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

#include <memory.h>
#include "displaying.h"
#include "calcul.h"
#include <stdlib.h>
#include <libft.h>

float	_find_length(float length, t_scene *scene, t_coord *pos, t_coord *axis)
{
	float		length_temp;
	int 		k;
	float		limit;

	limit = 0.0f;
	if (pos != scene->camera->r_pos)
		limit = 0.01f;
	k = -1;
	while (scene->plane && scene->plane[++k])
	{
		length_temp = _inter_plane(pos, scene->plane[k], axis);
		if (length_temp >= limit && (length_temp < length || length == -1))
		{
			length = length_temp;
			scene->object = scene->plane[k];
			scene->fct = _intensity_of_plane;
			scene->rgb_object = scene->plane[k]->color;
		}
	}
	k = -1;
	while (scene->sphere && scene->sphere[++k])
	{
		length_temp = _inter_sphere(pos, scene->sphere[k], axis);
		if (length_temp >= limit && (length_temp < length || length == -1))
		{
			length = length_temp;
			scene->object = scene->sphere[k];
			scene->fct = _intensity_of_sphere;
			scene->rgb_object = scene->sphere[k]->color;
		}
	}
	k = -1;
	while (scene->cylinder && scene->cylinder[++k])
	{
		length_temp = _inter_cylinder(pos, scene->cylinder[k], axis);
		if (length_temp >= limit && (length_temp < length || length == -1))
		{
			length = length_temp;
			scene->object = scene->cylinder[k];
			scene->fct = _intensity_of_cylinder;
			scene->rgb_object = scene->cylinder[k]->color;
		}
	}
	return (length);
}

static void	_generate_pixel(t_glob *data, int i, int j)
{
	float		length;
	float		intensity;
	int			*rgb;

	length = -1;
	length = _find_length(length, data->scene, data->scene->camera->r_pos, data->scene->axis[i][j]);
	if (length == -1)
		return ;
	intensity = data->scene->fct(data->scene, length, data->scene->object, data->scene->axis[i][j]);
	if (intensity < 0)
		intensity = 0;
	rgb = _rgb_render(data->scene, intensity, length);
	_mlx_pixel_put(data->window->img, i, j, rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	free (rgb);
}

void	_generate_image(t_glob *data)
{
	int	i;
	int	j;

	i = 0;
	_rebase_objects(data->scene);
	while (i < X_SSIZE)
	{
		j = 0;
		while (j < Y_SSIZE)
		{
			_generate_pixel(data, i, j);
			j++;
		}
		i++;
	}
}

t_coord	***_generate_axis(t_cam *camera, t_coord ***axis)
{
	int	i;
	int	j;

	i = 0;
	axis = ft_calloc(X_SSIZE, sizeof(t_coord **));
	if (!axis)
		return (NULL);
	while (i < X_SSIZE)
	{
		j = 0;
		axis[i] = ft_calloc(Y_SSIZE, sizeof(t_coord *));
		if (!axis[i])
			return (_free_axis(axis, i - 1, Y_SSIZE), NULL);
		while (j < Y_SSIZE)
		{
			axis[i][j] = _direct_axis(camera, i, j);
			if (!axis[i][j])
				return (_free_axis(axis, i, j - 1), NULL);
			j++;
		}
		i++;
	}
	return (axis);
}
