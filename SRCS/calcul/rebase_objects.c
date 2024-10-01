/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebase_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:49:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/10/01 13:32:45 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "structure.h"

static void	_rebase_coord(t_coord *r_coord, t_coord *coord, t_coord *base)
{
	float	angle[2];
	t_coord	temp;

	angle[0] = asinf(base->y);
	angle[1] = atan2f(base->x, base->z);
	temp.x = cosf(angle[1]) * coord->x - sinf(angle[1]) * coord->z;
	temp.y = coord->y;
	temp.z = sinf(angle[1]) * coord->x + cosf(angle[1]) * coord->z;
	r_coord->x = temp.x;
	r_coord->y = cosf(angle[0]) * temp.y + sinf(angle[0]) * temp.z;
	r_coord->z = -sinf(angle[0]) * temp.y + cosf(angle[0]) * temp.z;
}

static void	_rebase_plane(t_scene *scene)
{
	int	k;

	k = -1;
	while (scene->plane && scene->plane[++k])
	{
		_rebase_coord(scene->plane[k]->r_pos, scene->plane[k]->pos,
			scene->camera->vect);
		_rebase_coord(scene->plane[k]->r_vect, scene->plane[k]->vect,
			scene->camera->vect);
	}
}

static void	_rebase_cylinder(t_scene *scene)
{
	int	k;

	k = -1;
	while (scene->cylinder && scene->cylinder[++k])
	{
		_rebase_coord(scene->cylinder[k]->r_pos, scene->cylinder[k]->pos,
			scene->camera->vect);
		_rebase_coord(scene->cylinder[k]->r_vect, scene->cylinder[k]->vect,
			scene->camera->vect);
	}
}

void	_rebase_objects(t_scene *scene)
{
	int	k;

	k = -1;
	_rebase_plane(scene);
	while (scene->sphere && scene->sphere[++k])
		_rebase_coord(scene->sphere[k]->r_pos, scene->sphere[k]->pos,
			scene->camera->vect);
	_rebase_cylinder(scene);
	_rebase_coord(scene->light->r_pos, scene->light->pos,
		scene->camera->vect);
	_rebase_coord(scene->camera->r_pos, scene->camera->pos,
		scene->camera->vect);
}
