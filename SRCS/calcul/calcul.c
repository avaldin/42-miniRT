/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:35 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/20 18:30:30 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structure.h"
#include "libft.h"
#include "calcul.h"
#include <memory.h>

void	_normalized(t_coord *vect)
{
	float	norm;

	norm = sqrt(_sq(vect->x) + _sq(vect->y) + _sq(vect->z));
	vect->x = vect->x / norm;
	vect->y = vect->y / norm;
	vect->z = vect->z / norm;
}

t_coord	*_direct_axis(t_cam *camera, int i, int j)
{
	t_coord	*axis;
	float	angle[2];

	angle[0] = ((float )i / (float )X_SSIZE - 0.50f) * camera->fov;
	angle[1] = (0.50f - (float )j / (float )Y_SSIZE) * camera->fov / (float )((float )X_SSIZE / (float )Y_SSIZE);
	axis = _alloc_coord(sinf(angle[0]) * cosf(angle[1]), sinf(angle[1]), cosf(angle[0]) * cosf(angle[1]));
	if (!axis)
		return (NULL);
	_normalized(axis);
	return (axis);
}

float	_sq(float x)
{
	return (x * x); // proteger l'overflow
}

float	_projection(t_coord	point, t_coord *pos, t_coord *vect)
{
	return (sqrtf(_sq(((point.x - pos->x) * vect->x
		+ (point.y - pos->y) * vect->y
		+ (point.z - pos->z) * vect->z)
		/ sqrtf(_sq(vect->x) + _sq(vect->y) + _sq(vect->z)))));
}
