/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:03:00 by avaldin           #+#    #+#             */
/*   Updated: 2024/10/21 15:39:25 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calcul.h"
#include "structure.h"
#include <math.h>

t_coord	_intersection_on_line(t_coord *pos, t_coord *axis, float length)
{
	t_coord	intersection;

	intersection.x = pos->x + axis->x * length;
	intersection.y = pos->y + axis->y * length;
	intersection.z = pos->z + axis->z * length;
	return (intersection);
}

static float	_inter_disk(t_cylinder *cylinder, t_coord *axis,
	t_coord *cam_pos, float height)
{
	float	length;
	t_coord	pos;
	t_coord	intersection;

	if ((cylinder->r_vect->x * axis->x
			+ cylinder->r_vect->y * axis->y
			+ cylinder->r_vect->z * axis->z) == 0)
		return (-1);
	pos.x = cylinder->r_pos->x + cylinder->r_vect->x * height;
	pos.y = cylinder->r_pos->y + cylinder->r_vect->y * height;
	pos.z = cylinder->r_pos->z + cylinder->r_vect->z * height;
	length = -(cylinder->r_vect->x * cam_pos->x + cylinder->r_vect->y
			* cam_pos->y + cylinder->r_vect->z * cam_pos->z
			- (cylinder->r_vect->x * pos.x + cylinder->r_vect->y
				* pos.y + cylinder->r_vect->z
				* pos.z)) / (cylinder->r_vect->x * axis->x + cylinder->r_vect->y
			* axis->y + cylinder->r_vect->z * axis->z);
	intersection = _intersection_on_line(cam_pos, axis, length);
	if (sqrt(_sq(_sq(intersection.x - pos.x)
				+ _sq(intersection.y - pos.y) + _sq(intersection.z - pos.z)))
		<= _sq(cylinder->radius))
		return (length);
	else
		return (-1);
}

void	_calcul_var_cylinder(float *eq_var, t_coord *axis, t_cylinder *cylinder,
	t_coord *pos)
{
	eq_var[0] = _sq(axis->x) + _sq(axis->y) + _sq(axis->z)
		- _sq(cylinder->r_vect->x * axis->x + cylinder->r_vect->y * axis->y
			+ cylinder->r_vect->z * axis->z);
	eq_var[1] = 2.0f * (axis->x * (pos->x - cylinder->r_pos->x) + axis->y
			* (pos->y - cylinder->r_pos->y) + axis->z * (pos->z
				- cylinder->r_pos->z) - (cylinder->r_vect->x * axis->x
				+ cylinder->r_vect->y * axis->y + cylinder->r_vect->z
				* axis->z) * (cylinder->r_vect->x * (pos->x
					- cylinder->r_pos->x) + cylinder->r_vect->y * (pos->y
					- cylinder->r_pos->y) + cylinder->r_vect->z * (pos->z
					- cylinder->r_pos->z)));
	eq_var[2] = _sq(pos->x - cylinder->r_pos->x) + _sq(pos->y
			- cylinder->r_pos->y) + _sq(pos->z - cylinder->r_pos->z)
		- _sq(cylinder->r_vect->x * (pos->x - cylinder->r_pos->x)
			+ cylinder->r_vect->y * (pos->y - cylinder->r_pos->y)
			+ cylinder->r_vect->z * (pos->z - cylinder->r_pos->z))
		- _sq(cylinder->radius);
}

float	_inter_cylinder_b(t_coord *pos, t_cylinder *cylinder, t_coord *axis,
	float *result)
{
	int	i;

	result[2] = _inter_disk(cylinder, axis, pos, cylinder->height / 2.0f);
	result[3] = _inter_disk(cylinder, axis, pos, -cylinder->height / 2.0f);
	i = -1;
	while (++i < 4)
	{
		if ((result[i] < result[4] || result[4] == -1.0f) && result[i] >= 0.01f)
		{
			result[4] = result[i];
			cylinder->part = i;
		}
	}
	return (result[4]);
}
