/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:49:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/16 23:08:20 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displaying.h"
#include "calcul.h"

static float	_find_length(float length, t_scene *scene, int i, int j)
{
	float		length_temp;
	int 		k;
	t_coord		*axis;


	k = -1;
	axis = _direct_axis(scene, i, j, scene->var);
	while (scene->plane[++k])
	{
		length_temp = _inter_plane(scene, scene->plane[k], axis);
		if (length_temp >= 0 && (length_temp < length || length == -1))
		{
			length = length_temp;
			scene->object = scene->plane[k];
			scene->fct = _intensity_of_plane;
			scene->rgb_object = scene->plane[k]->color;
		}
	}
	k = -1;
	while (scene->sphere[++k])
	{
		length_temp = _inter_sphere(scene, scene->sphere[k], axis);
		if (length_temp >= 0 && (length_temp < length || length == -1))
		{
			length = length_temp;
			scene->object = scene->sphere[k];
			scene->fct = _intensity_of_sphere;
			scene->rgb_object = scene->sphere[k]->color;
		}
	}
//	k = -1;
//	while (scene->cylinder[++k])
//	{
//		length_temp = _inter_plane();
//		if (length_temp >= 0 && length_temp < length)
//			length = length_temp;
//	}
	return (length);
}

#include "stdio.h"

static void	_generate_pixel(t_scene *scene, int i, int j)
{
	float		length;
	float		intensity;
	int			*rgb;

	length = -1;
	length = _find_length(length, data->scene, i, j);
	if (length == -1)
		return ;
	intensity = scene->fct(scene, length, scene->object);
	if (intensity < 0)
		intensity = 0;
	//printf("l = %f, y = %d\n", length, j);
	rgb = _rgb_render(scene, intensity, length);
	_mlx_pixel_put(scene->data, i, j, rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	_generate_image(t_glob *data)
{
	int	i;
	int	j;

	i = 0;
	_matrix_var(data->scene);
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
