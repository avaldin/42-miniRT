/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_check_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 00:30:03 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/12 18:08:18 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "structure.h"
#include <stdlib.h>

t_check	_check_sphere(t_sphere **sphere, char *line)
{
	t_sphere	*temp_sph;

	temp_sph = *sphere;
	if ((line && *line != '\n' && *line)
		|| _check_rgb(temp_sph->color)
		|| !(temp_sph->radius > 0))
	{
		if (temp_sph->color)
			free (temp_sph->color);
		if (temp_sph->pos)
			free (temp_sph->pos);
		*sphere = NULL;
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_plane(t_plane **plane, char *line)
{
	t_plane	*temp_pln;

	temp_pln = *plane;
	if ((line && *line != '\n' && *line)
		|| _check_rgb(temp_pln->color)
		|| _check_coord(temp_pln->vect, -1., 1.))
	{
		if (temp_pln->color)
			free (temp_pln->color);
		if (temp_pln->pos)
			free (temp_pln->pos);
		if (temp_pln->vect)
			free (temp_pln->vect);
		*plane = NULL;
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_cylinder(t_cylinder **cylinder, char *line)
{
	t_cylinder	*temp_cyl;

	temp_cyl = *cylinder;
	if ((line && *line != '\n' && *line)
		|| _check_rgb(temp_cyl->color)
		|| _check_coord(temp_cyl->vect, -1., 1.)
		|| !(temp_cyl->radius > 0)
		|| !(temp_cyl->height > 0))
	{
		if (temp_cyl->color)
			free (temp_cyl->color);
		if (temp_cyl->pos)
			free (temp_cyl->pos);
		if (temp_cyl->vect)
			free (temp_cyl->vect);
		*cylinder = NULL;
		return (FAILURE);
	}
	return (SUCCESS);	
}