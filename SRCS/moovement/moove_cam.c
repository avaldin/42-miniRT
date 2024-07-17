/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:54:14 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 17:31:03 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"

t_mvt	*init_mvt_struct(t_cam *cam)
{
	static t_mvt	kinetic;

	kinetic.mv_x = 0;
	kinetic.mv_y = 0;
	kinetic.dir_x = _alloc_coord(cam->vect->x, cam->vect->y, cam->vect->z);
	kinetic.dir_y = _alloc_coord(cam->vect->x, cam->vect->y, 0.);
	kinetic.dir_bx = _alloc_coord(-cam->vect->x, -cam->vect->y, -cam->vect->z);
	kinetic.dir_by = _alloc_coord(cam->vect->x, -cam->vect->y, 0.);
	if (!kinetic.dir_x || !kinetic.dir_y || !kinetic.dir_bx || !kinetic.dir_by)
		return (_free_mvt(&kinetic), NULL);
	return (&kinetic);
}