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
#include "../HDRS/calcul.h"

float	_find_intensity(t_scene *scene, float length)
{
	float	i;
	t_coord	inter;
	t_coord	v_normal;
	t_coord	v_light;

	inter.x = scene->camera->pos->x + length * scene->axis->x;
	inter.y = scene->camera->pos->y + length * scene->axis->y;
	inter.z = scene->camera->pos->z + length * scene->axis->z;
	v_normal.x = inter.x - scene->sphere
}

// x0 + length * direction