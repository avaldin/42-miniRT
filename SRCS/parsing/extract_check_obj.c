/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_check_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:30:03 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/05 14:04:28 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "structure.h"
#include <stdlib.h>

t_check	_check_sphere(t_sphere *sphere, char *line)
{
	if ((line && *line != '\n' && *line)
		|| _check_rgb(sphere->color)
		|| _check_coord(sphere->pos, -100., 100.)
		|| !(sphere->radius > 0))
	{
		if (sphere->color)
			free (sphere->color);
		if (sphere->pos)
			free (sphere->pos);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_plane(t_plane *plane, char *line)
{
	if ((line && *line != '\n' && *line)
		|| _check_rgb(plane->color)
		|| _check_coord(plane->pos, -100., 100.)
		|| _check_coord(plane->vect, -1., 1.))
	{
		if (plane->color)
			free (plane->color);
		if (plane->pos)
			free (plane->pos);
		if (plane->vect)
			free (plane->vect);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_cylinder(t_cylinder *cylinder, char *line)
{
	if ((line && *line != '\n' && *line)
		|| _check_rgb(cylinder->color)
		|| _check_coord(cylinder->pos, -100., 100.)
		|| _check_coord(cylinder->vect, -1., 1.)
		|| !(cylinder->radius > 0)
		|| !(cylinder->height > 0))
	{
		if (cylinder->color)
			free (cylinder->color);
		if (cylinder->pos)
			free (cylinder->pos);
		if (cylinder->vect)
			free (cylinder->vect);
		return (FAILURE);
	}
	return (SUCCESS);	
}