/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:49:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/10/21 15:40:05 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "displaying.h"
#include "calcul.h"
#include <stdlib.h>
#include <libft.h>

float	_find_length(float length, t_scene *scene, t_coord *pos, t_coord *axis)
{
	length = _nearest_plane(length, pos, scene, axis);
	length = _nearest_sphere(length, pos, scene, axis);
	length = _nearest_cylinder(length, pos, scene, axis);
	return (length);
}

static void	_generate_pixel(t_glob *data, int i, int j)
{
	float		length;
	float		intensity;
	int			rgb;

	length = -1;
	length = _find_length(length, data->scene, data->scene->camera->r_pos,
			data->scene->axis[i][j]);
	if (length == -1)
		return ;
	intensity = data->scene->fct(data->scene, length, data->scene->object,
			data->scene->axis[i][j]);
	if (intensity < 0)
		intensity = 0;
	rgb = _rgb_render(data->scene, intensity, length);
	_mlx_pixel_put(data->window->img, i, j, rgb);
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
	axis = ft_calloc(X_SSIZE + 1, sizeof(t_coord **));
	if (!axis)
		return (NULL);
	while (i < X_SSIZE)
	{
		j = 0;
		axis[i] = ft_calloc(Y_SSIZE + 1, sizeof(t_coord *));
		if (!axis[i])
			return (_free_axis(axis), NULL);
		while (j < Y_SSIZE)
		{
			axis[i][j] = _direct_axis(camera, i, j);
			if (!axis[i][j])
				return (_free_axis(axis), NULL);
			j++;
		}
		i++;
	}
	return (axis);
}
