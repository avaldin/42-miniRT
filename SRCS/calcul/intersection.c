/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:03:00 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 18:55:26 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "calcul.h"
#include <math.h>
#include <memory.h>

float	_inter_plane(t_coord *pos, t_plane *plane, t_coord *axis)
{
	plane->cst = -(plane->r_vect->x * plane->r_pos->x + plane->r_vect->y
			* plane->r_pos->y + plane->r_vect->z * plane->r_pos->z);
	if ((plane->r_vect->x * axis->x
			+ plane->r_vect->y * axis->y
			+ plane->r_vect->z * axis->z) == 0)
		return (-1);
	return (-(plane->r_vect->x * pos->x + plane->r_vect->y * pos->y
			+ plane->r_vect->z * pos->z + plane->cst)
		/ (plane->r_vect->x * axis->x
			+ plane->r_vect->y * axis->y
			+ plane->r_vect->z * axis->z));
}

float	_inter_sphere(t_coord *pos, t_sphere *sphere, t_coord *axis)
{
	float	result[2];
	float	a;
	float	b;
	float	c;

	a = 1;
	b = 2.0f * ((pos->x - sphere->r_pos->x) * axis->x
			+ (pos->y - sphere->r_pos->y) * axis->y
			+ (pos->z - sphere->r_pos->z) * axis->z);
	c = _sq(pos->x - sphere->r_pos->x) + _sq(pos->y - sphere->r_pos->y)
		+ _sq(pos->z - sphere->r_pos->z) - _sq(sphere->radius);
	if (_sq(b) - 4.0f * a * c < 0)
		return (-1);
	result[0] = _eq_sec_deg(a, b, c, 1.0f);
	result[1] = _eq_sec_deg(a, b, c, -1.0f);
	if ((result[0] >= 0 && result[0] < result[1]) || result[1] < 0)
		return (result[0]);
	return (result[1]);
}

float	_inter_cylinder(t_coord *pos, t_cylinder *cylinder, t_coord *axis)
{
	float	eq_var[3];
	float	discriminant;
	float	result[5];

	result[4] = -1;
	_calcul_var_cylinder(eq_var, axis, cylinder, pos);
	discriminant = _sq(eq_var[1]) - 4.0f * eq_var[0] * eq_var[2];
	result[0] = -1;
	result[1] = -1;
	if (discriminant < 0)
		return (-1);
	result[0] = (-eq_var[1] - sqrtf(discriminant)) / (2.0f * eq_var[0]);
	if (sqrtf(_sq(_projection(_intersection_on_line(pos, axis,
						result[0]), cylinder->r_pos, cylinder->r_vect)))
		> cylinder->height / 2.0f)
		result[0] = -1;
	result[1] = (-eq_var[1] + sqrtf(discriminant)) / (2.0f * eq_var[0]);
	if (sqrtf(_sq(_projection(_intersection_on_line(pos, axis,
						result[1]), cylinder->r_pos, cylinder->r_vect)))
		> cylinder->height / 2.0f)
		result[1] = -1;
	return (_inter_cylinder_b(pos, cylinder, axis, result));
}

t_coord	*_direct_axis(t_cam *camera, int i, int j)
{
	t_coord	*axis;
	float	angle[2];

	angle[0] = ((float )i / (float )X_SSIZE - 0.50f) * camera->fov;
	angle[1] = (0.50f - (float )j / (float )Y_SSIZE) * camera->fov
		/ ((float )X_SSIZE / (float )Y_SSIZE);
	axis = _alloc_coord(sinf(angle[0]) * cosf(angle[1]),
			sinf(angle[1]), cosf(angle[0]) * cosf(angle[1]));
	if (!axis)
		return (NULL);
	_normalized(axis);
	return (axis);
}
