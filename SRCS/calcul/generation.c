/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:49:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/07 00:14:46 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"
#include "calcul.h"
#include "libft.h"

static float	_find_length(float length, t_scene *scene, int i, int j)
{
	float		length_temp;
	int 		k;


	k = -1;
//	while (scene->plane[++k])
//	{
//		length_temp = _inter_plane(scene, scene->plane[k], i, j);
//		if (length_temp >= 0 && length_temp < length)
//			length = length_temp;
//	}
//	k = -1;
	while (scene->sphere[++k])
	{
		length_temp = _inter_sphere(scene, scene->sphere[k], i, j);
		if (length_temp >= 0 && (length_temp < length || length == -1))
			length = length_temp;
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

static void	_generate_pixel(t_scene *scene, int i, int j)
{
	float		length;
	float		intensity;
	float		temp;
	int			color;

	length = -1;
	length = _find_length(length, scene, i, j);
	if (length == -1)
	{
		return ;
	}
	// if light == 0 (p[ixel put lumiere ambiante)
	intensity = _find_intensity(scene, length);
	if (intensity < 0)
		return ;
	temp = 255.0 * intensity / scene->light->ratio;
	color = (int)temp;
	if ((float)((int)temp) + 0.5 < temp)
		color++;
	_mlx_pixel_put(scene->data, i, j, color << 16);
}
void	_generate_image(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	_matrix_var(scene);
	while (i < scene->x_screen)
	{
		j = 0;
		while (j < scene->y_screen)
		{
			_generate_pixel(scene, i, j);
			j++;
		}
		i++;
	}
}