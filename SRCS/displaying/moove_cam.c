/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:54:14 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/20 03:39:27 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"
#include "calcul.h"
#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "../../include/minilibx-linux/mlx.h"

void	_change_cam_pos(t_cam *cam, t_coord *matrix, float mv)
{
	float	nvec;

	nvec = (float)sqrt(pow(matrix->x, 2.) + pow(matrix->y, 2.) + pow(matrix->z, 2.));
	cam->pos->x = cam->pos->x + (mv * ((matrix->x) / nvec));
	cam->pos->y = cam->pos->y + (mv * ((matrix->y) / nvec));
	cam->pos->z = cam->pos->z + (mv * ((matrix->z) / nvec));
}

float	_change_cam_direction(int old_pos, int new_pos)
{
	float	mv;

	mv = old_pos - new_pos;
	return (mv * 0.01 / 500.); 
}

t_check	_init_mvt_struct(t_kntc *kinetic, t_cam *cam)
{
	static	t_mvt	moov;
	static	t_rtn	rotate;
	
	moov.mv_x = 0;
	moov.mv_y = 0;
	moov.dir_x = _alloc_coord(cam->vect->x, cam->vect->y, cam->vect->z);
	moov.dir_y = _alloc_coord(-cam->vect->x, cam->vect->y, 0.);
	moov.dir_bx = _alloc_coord(-cam->vect->x, -cam->vect->y, -cam->vect->z);
	moov.dir_by = _alloc_coord(cam->vect->x, cam->vect->y, 0.);
	rotate.last_x = -1;
	rotate.last_y = -1;
	rotate.s_input = OUT;
	kinetic->cam_moov = &moov;
	kinetic->cam_rotate = &rotate;
	if (moov.dir_x && moov.dir_y && moov.dir_bx && moov.dir_by)
		return (SUCCESS);
	_free_mvt(&moov);
	return (FAILURE);
}