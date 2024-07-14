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
#include <libft.h>
#include "../../HDRS/calcul.h"
#include <math.h>

float	_find_intensity(t_scene *scene, float length)
{
	float	i;
	t_coord	inter;
	t_coord	v_normal;
	t_coord	v_light;

	inter.x = scene->camera->pos->x + length * scene->axis->x;
	inter.y = scene->camera->pos->y + length * scene->axis->y;
	inter.z = scene->camera->pos->z + length * scene->axis->z;
	v_normal.x = inter.x - scene->sphere[0]->pos->x;
	v_normal.y = inter.y - scene->sphere[0]->pos->y;
	v_normal.z = inter.z - scene->sphere[0]->pos->z;
	v_light.x = scene->light->pos->x - inter.x ;
	v_light.y = scene->light->pos->y - inter.y;
	v_light.z = scene->light->pos->z - inter.z;
	//shadow here
	i = scene->light->ratio * 1.0f * (v_normal.x * v_light.x + v_normal.y * v_light.y
		+ v_normal.z * v_light.z) / (sqrtf(_sq(v_light.x) + _sq(v_light.y)
		+ _sq(v_light.z)) * sqrtf(_sq(v_normal.x) + _sq(v_normal.y) + _sq(v_normal.z)));
	return (i);
}

int	*_rgb_render(t_scene *scene, float intensity)
{
	int		*rgb;
	float	temp;

	rgb = ft_calloc(3, sizeof(int));
	temp = (scene->light->color->red * intensity
		+ scene->ambient->color->red * scene->ambient->ratio)
		/ (scene->light->ratio + scene->ambient->ratio);
	rgb[0] = (int)temp;
	if ((float)((int)temp) + 0.5 < temp)
		rgb[0]++;
	temp = (scene->light->color->green * intensity
		+ scene->ambient->color->green * scene->ambient->ratio)
		/ (scene->light->ratio + scene->ambient->ratio);
	rgb[1] = (int)temp;
	if ((float)((int)temp) + 0.5 < temp)
		rgb[1]++;
	temp = (scene->light->color->blue * intensity
		+ scene->ambient->color->blue * scene->ambient->ratio)
		/ (scene->light->ratio + scene->ambient->ratio);
	rgb[2] = (int)temp;
	if ((float)((int)temp) + 0.5 < temp)
		rgb[2]++;
	return (rgb);
}