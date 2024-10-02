/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:35 by avaldin           #+#    #+#             */
/*   Updated: 2024/10/02 18:53:43 by tmouche          ###   ########.fr       */
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

float	_sq(float x)
{
	return (x * x);
}

float	_projection(t_coord	point, t_coord *pos, t_coord *vect)
{
	return (sqrtf(_sq(((point.x - pos->x) * vect->x
					+ (point.y - pos->y) * vect->y
					+ (point.z - pos->z) * vect->z)
				/ sqrtf(_sq(vect->x) + _sq(vect->y) + _sq(vect->z)))));
}

float	_eq_sec_deg(float a, float b, float c, float sign)
{
	return ((-b + sign * sqrtf(_sq(b) - 4.0f * a * c)) / (2.0f * a));
}

int	_float_to_int(float f)
{
	int	i;

	i = (int)f;
	if ((float)((int)f) + 0.5 < f)
		i++;
	return (i);
}
