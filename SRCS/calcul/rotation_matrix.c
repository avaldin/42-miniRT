/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 23:51:55 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/21 02:28:54 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <calcul.h>
#include <structure.h>

static inline void	_rotation_matrix_2d(float table[2][2], float rad_ang)
{
	table[0][0] = cos(rad_ang);
	table[0][1] = -sin(rad_ang);
	table[1][0] = sin(rad_ang);
	table[1][1] = cos(rad_ang);
}

static inline void	_rotation_matrix_3d(float table[3][3], t_coord *axis, float rad_ang)
{
	const float	cos_ang = cos(rad_ang);
	const float	sin_ang = sin(rad_ang);

	table[0][0] = 1 - (1 - cos_ang) * (axis->y * axis->y + axis->z * axis->z);
	table[0][1] = -sin_ang * axis->z + (1 - cos_ang) * axis->x * axis->y;
	table[0][2] = sin_ang * axis->y + (1 - cos_ang) * axis->x * axis->z;
	table[1][0] = sin_ang * axis->z + (1 - cos_ang) * axis->y * axis->x;
	table[1][1] = 1 - (1 - cos_ang) * (axis->x * axis->x + axis->z * axis->z);
	table[1][2] = -sin_ang * axis->x + (1 - cos_ang) * axis->y * axis->z;
	table[2][0] = -sin_ang * axis->y + (1 - cos_ang) * axis->z * axis->x;
	table[2][1] = sin_ang * axis->y + (1 - cos_ang) * axis->z * axis->y;
	table[2][2] = 1 - (1 - cos_ang) * (axis->x * axis->x + axis->y * axis->y);
}

void	_rotate_vec_2d(float *x, float *y, float angle)
{
	float	r[2][2];
	float	x_prime;
	float	y_prime;

	_rotation_matrix_2d(r, _PI / 180 * angle);
	x_prime = r[0][0] * *x + r[0][1] * *y;
	y_prime = r[1][0] * *x + r[1][1] * *y;
	*x = x_prime;
	*y = y_prime;
}

void	_rotate_vec_3d(t_coord *vec, t_coord *axis, float angle)
{
	float	r[3][3];
	float	x_prime;
	float	y_prime;
	float	z_prime;

	_rotation_matrix_3d(r, axis, _PI / 180 * angle);
	x_prime = r[0][0] * vec->x + r[0][1] * vec->y + r[0][2] * vec->z;
	y_prime = r[1][0] * vec->x + r[1][1] * vec->y + r[1][2] * vec->z;
	z_prime = r[2][0] * vec->x + r[2][1] * vec->y + r[2][2] * vec->z;
	vec->x = x_prime;
	vec->y = y_prime;
	vec->z = z_prime;
}
