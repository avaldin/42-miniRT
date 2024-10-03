/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:51:55 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/02 16:21:13 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <calcul.h>
#include <structure.h>

static inline void	_rotation_matrix_3d(float table[3][3],
			t_coord const *u, float rad_ang)
{
	const float	c = cos(rad_ang);
	const float	s = sin(rad_ang);

	table[0][0] = (u->x * u->x) + (1 - u->x * u->x) * c;
	table[0][1] = (u->x * u->y) * (1 - c) - (u->z * s);
	table[0][2] = (u->x * u->z) * (1 - c) + (u->y * s);
	table[1][0] = (u->x * u->y) * (1 - c) + (u->z * s);
	table[1][1] = (u->y * u->y) + (1 - u->y * u->y) * c;
	table[1][2] = (u->y * u->z) * (1 - c) - (u->x * s);
	table[2][0] = (u->x * u->z) * (1 - c) - (u->y * s);
	table[2][1] = (u->y * u->z) * (1 - c) + (u->x * s);
	table[2][2] = (u->z * u->z) + (1 - u->z * u->z) * c;
}

void	_rotate_vec_3d(t_coord *vec, t_coord const *axis, float angle)
{
	float	r[3][3];
	float	x_prime;
	float	y_prime;
	float	z_prime;

	_rotation_matrix_3d(r, axis, angle);
	x_prime = r[0][0] * vec->x + r[0][1] * vec->y + r[0][2] * vec->z;
	y_prime = r[1][0] * vec->x + r[1][1] * vec->y + r[1][2] * vec->z;
	z_prime = r[2][0] * vec->x + r[2][1] * vec->y + r[2][2] * vec->z;
	vec->x = x_prime;
	vec->y = y_prime;
	vec->z = z_prime;
}
