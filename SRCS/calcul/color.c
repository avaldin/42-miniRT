/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:49:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/10/14 16:15:42 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include "../../HDRS/calcul.h"
#include <math.h>

float	_intensity_of_plane(t_scene *scene, float length, void *object,
	t_coord *axis)
{
	t_plane	*plane;
	t_coord	inter;
	t_coord	v_light;
	float	i;

	plane = (t_plane *)object;
	inter = _intersection_on_line(scene->camera->r_pos, axis, length);
	v_light.x = scene->light->r_pos->x - inter.x;
	v_light.y = scene->light->r_pos->y - inter.y;
	v_light.z = scene->light->r_pos->z - inter.z;
	_normalized(&v_light);
	i = _find_length(-1, scene, &inter, &v_light);
	if (i > 0 && i < sqrtf(_sq(scene->light->r_pos->x - inter.x)
			+ _sq(scene->light->r_pos->y - inter.y)
			+ _sq(scene->light->r_pos->z - inter.z)))
		return (0);
	i = -1;
	if ((plane->r_vect->x * axis->x + plane->r_vect->y * axis->y
			+ plane->r_vect->z * axis->z) <= 0)
		i = 1;
	return (i * scene->light->ratio * 1.0f * (plane->r_vect->x * v_light.x
			+ plane->r_vect->y * v_light.y + plane->r_vect->z * v_light.z)
		/ (sqrtf(_sq(v_light.x) + _sq(v_light.y) + _sq(v_light.z))
			* sqrtf(_sq(plane->r_vect->x) + _sq(plane->r_vect->y)
				+ _sq(plane->r_vect->z))));
}

float	_intensity_of_sphere(t_scene *scene, float length, void *object,
	t_coord *axis)
{
	t_sphere	*sphere;
	t_coord		inter;
	t_coord		v_normal;
	t_coord		v_light;

	sphere = (t_sphere *)object;
	inter = _intersection_on_line(scene->camera->r_pos, axis, length);
	v_normal.x = inter.x - sphere->r_pos->x;
	v_normal.y = inter.y - sphere->r_pos->y;
	v_normal.z = inter.z - sphere->r_pos->z;
	v_light.x = scene->light->r_pos->x - inter.x ;
	v_light.y = scene->light->r_pos->y - inter.y;
	v_light.z = scene->light->r_pos->z - inter.z;
	_normalized(&v_light);
	length = _find_length(-1, scene, &inter, &v_light);
	if (length > 0 && length < sqrtf(_sq(scene->light->r_pos->x - inter.x)
			+ _sq(scene->light->r_pos->y - inter.y)
			+ _sq(scene->light->r_pos->z - inter.z)))
		return (0);
	return (scene->light->ratio * 1.0f * (v_normal.x * v_light.x + v_normal.y
			* v_light.y + v_normal.z * v_light.z) / (sqrtf(_sq(v_light.x)
				+ _sq(v_light.y) + _sq(v_light.z)) * sqrtf(_sq(v_normal.x)
				+ _sq(v_normal.y) + _sq(v_normal.z))));
}

void	_normal_cylinder(t_cylinder *cylinder, t_coord *v_normal, t_coord inter)
{
	if (cylinder->part == 2)
	{
		v_normal->x = cylinder->r_vect->x;
		v_normal->y = cylinder->r_vect->y;
		v_normal->z = cylinder->r_vect->z;
	}
	else if (cylinder->part == 3)
	{
		v_normal->x = -cylinder->r_vect->x;
		v_normal->y = -cylinder->r_vect->y;
		v_normal->z = -cylinder->r_vect->z;
	}
	else
	{
		v_normal->x = inter.x - cylinder->r_pos->x - (inter.x - cylinder->r_pos->x) * cylinder->r_vect->x;
		v_normal->y = inter.y - cylinder->r_pos->y - (inter.y - cylinder->r_pos->y) * cylinder->r_vect->y;
		v_normal->z = inter.z - cylinder->r_pos->z - (inter.z - cylinder->r_pos->z) * cylinder->r_vect->z;
	}
}

float	_intensity_of_cylinder(t_scene *scene, float length, void *object,
	t_coord *axis)
{
	t_cylinder	*cylinder;
	t_coord		inter;
	t_coord		v_normal;
	t_coord		v_light;

	cylinder = (t_cylinder *)object;
	inter = _intersection_on_line(scene->camera->r_pos, axis, length);
	_normal_cylinder(cylinder, &v_normal, inter);
	v_light.x = scene->light->r_pos->x - inter.x;
	v_light.y = scene->light->r_pos->y - inter.y;
	v_light.z = scene->light->r_pos->z - inter.z;
	_normalized(&v_light);
	length = _find_length(-1, scene, &inter, &v_light);
	if (length > 0 && length < sqrtf(_sq(scene->light->r_pos->x - inter.x)
			+ _sq(scene->light->r_pos->y - inter.y) + _sq(scene->light->r_pos->z
				- inter.z)))
		return (0);
	return (scene->light->ratio * 1.0f * (v_normal.x * v_light.x + v_normal.y
			* v_light.y + v_normal.z * v_light.z) / (sqrtf(_sq(v_light.x)
				+ _sq(v_light.y) + _sq(v_light.z)) * sqrtf(_sq(v_normal.x)
				+ _sq(v_normal.y) + _sq(v_normal.z))));
}

int	_rgb_render(t_scene *scene, float intensity, float length)
{
	int		rgb;
	float	temp;

	temp = ((float )scene->light->color->red * intensity
			+ (float )scene->ambient->color->red * scene->ambient->ratio
			* LENGTH_MITIGATION / (length + LENGTH_MITIGATION))
		/ (scene->light->ratio + scene->ambient->ratio);
	temp = temp * (float )scene->rgb_object->red / 255.0f;
	rgb = _float_to_int(temp) << 16;
	temp = ((float )scene->light->color->green * intensity
			+ (float )scene->ambient->color->green * scene->ambient->ratio
			* LENGTH_MITIGATION / (length + LENGTH_MITIGATION))
		/ (scene->light->ratio + scene->ambient->ratio);
	temp = temp * (float )scene->rgb_object->green / 255.0f;
	rgb = rgb | _float_to_int(temp) << 8;
	temp = ((float )scene->light->color->blue * intensity
			+ (float )scene->ambient->color->blue * scene->ambient->ratio
			* LENGTH_MITIGATION / (length + LENGTH_MITIGATION))
		/ (scene->light->ratio + scene->ambient->ratio);
	temp = temp * (float )scene->rgb_object->blue / 255.0f;
	return (rgb | _float_to_int(temp));
}
