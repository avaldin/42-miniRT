/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:49:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 18:24:16 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/calcul.h"

float	_find_length(float length, t_scene *scene, int i, int j)
{
	float		length_temp;
	int 		k;

	k = -1;
	while (scene->plane[++k])
	{
		length_temp = _inter_plane(scene, scene->plane[k], i, j);
		if (length_temp >= 0 && length_temp < length)
			length = length_temp;
	}
	k = -1;
	while (scene->sphere[++k])
	{
		length_temp = _inter_sphere();
		if (length_temp >= 0 && length_temp < length)
			length = length_temp;
	}
	k = -1;
	while (scene->cylinder[++k])
	{
		length_temp = _inter_plane();
		if (length_temp >= 0 && length_temp < length)
			length = length_temp;
	}
}

static void	_generate_pixel(t_scene *scene, int i, int j)
{
	float		length;

	length = -1;
	length = _find_length(length, scene, i, j);
}
void	_generate_image(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
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