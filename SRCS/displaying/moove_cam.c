/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:54:14 by thibaud           #+#    #+#             */
/*   Updated: 2024/10/27 19:58:52 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"
#include "calcul.h"
#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "../../include/minilibx-linux/mlx.h"

void	_change_cam_pos_z(t_cam *cam, t_coord *vect_dir, float mv)
{
	cam->pos->x = cam->pos->x + (mv * vect_dir->x);
	cam->pos->z = cam->pos->z + (mv * vect_dir->z);
	return ;
}

void	_change_cam_pos_x(t_cam *cam, t_coord *vect_dir, float mv)
{
	cam->pos->x = cam->pos->x + (mv * (vect_dir->x * 0 + vect_dir->z * -1));
	cam->pos->z = cam->pos->z + (mv * (vect_dir->x * 1 + vect_dir->z * 0));
	return ;
}

void	_change_cam_pos_y(t_cam *cam, float mv)
{
	cam->pos->y += mv;
	return ;
}

t_check	_init_mvt_struct(t_kntc *kinetic, t_cam *cam)
{
	static t_rtn	rotate;
	static t_mvt	moov;

	moov.mv_x = 0;
	moov.mv_y = 0;
	moov.dir_x = _alloc_coord(cam->vect->x, cam->vect->y, cam->vect->z);
	rotate.mv_x = 0;
	rotate.mv_y = 0;
	rotate.loc_x = X_SSIZE / 2;
	rotate.loc_y = Y_SSIZE / 2;
	kinetic->cam_moov = &moov;
	kinetic->cam_rotate = &rotate;
	if (moov.dir_x)
		return (SUCCESS);
	return (FAILURE);
}
