/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_check_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:58:37 by thibaud           #+#    #+#             */
/*   Updated: 2024/06/30 01:24:45 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include <stdlib.h>

t_check	_check_ambient(t_amb *ambient, char *line)
{
	if ((line && *line != '\n' && *line) 
		|| _check_rgb(ambient->color)
		|| !(ambient->ratio >= 0 && ambient->ratio <= 1))
	{
		if (ambient->color)
			free (ambient->color);
		free (ambient);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_camera(t_cam *camera, char *line)
{
	if ((line && *line != '\n' && *line)
		|| _check_coord(camera->pos, -100, 100)					//EN FONCTION DE LA TAILLE DE LA GRILLE ???
		|| _check_coord(camera->vect, -1., 1.)
		|| !(camera->fov >= 0 && camera->fov <= 180))
	{
		if (camera->pos)
			free (camera->pos);
		if (camera->vect)
			free (camera->vect);
		free (camera);
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_light(t_spot *light, char *line)
{
	if ((line && *line != '\n' && *line)
		|| _check_rgb(light->color) 
		|| _check_coord(light->pos, -100, 100)					//EN FONCTION DE LA TAILLE DE LA GRILLE ???
		|| !(light->ratio >= 0. && light->ratio <= 1.))
	{
		if (light->color)
			free (light->color);
		if (light->pos)
			free (light->pos);
		free (light);
		return (FAILURE);
	}
	return (SUCCESS);
}