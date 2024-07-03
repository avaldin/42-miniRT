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

#include "../HDRS/pixel.h"
#include "../HDRS/calcul.h"
#include "../include/libft/libft.h"

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


	length = -1;
	length = _find_length(length, scene, i, j);
	if (length != -1)
		_mlx_pixel_put(scene->data, i, j, 255);

}
void	_generate_image(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	_dov(scene, _matrix_var(scene));
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