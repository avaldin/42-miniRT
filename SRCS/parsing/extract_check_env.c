/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_check_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 23:58:37 by thibaud           #+#    #+#             */
/*   Updated: 2024/10/23 18:06:07 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "calcul.h"
#include <stdlib.h>

t_check	_check_ambient(t_amb **ambient, char *line)
{
	t_amb	*temp_amb;

	temp_amb = *ambient;
	if ((line && *line != '\n' && *line)
		|| _check_rgb(temp_amb->color)
		|| !(temp_amb->ratio >= 0 && temp_amb->ratio <= 1))
	{
		if (temp_amb->color)
			free (temp_amb->color);
		free (*ambient);
		*ambient = NULL;
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_camera(t_cam **camera, char *line)
{
	t_cam	*temp_cam;

	temp_cam = *camera;
	if ((line && *line != '\n' && *line)
		|| _check_coord(temp_cam->vect, -1., 1.)
		|| temp_cam->fov < 0 || temp_cam->fov > 180)
	{
		if (temp_cam->pos)
			free (temp_cam->pos);
		if (temp_cam->vect)
			free (temp_cam->vect);
		free (*camera);
		*camera = NULL;
		return (FAILURE);
	}
	(*camera)->fov = (*camera)->fov * _PI / 180.0f;
	return (SUCCESS);
}

t_check	_check_light(t_spot **light, char *line)
{
	t_spot	*temp_light;

	temp_light = *light;
	if ((line && *line != '\n' && *line)
		|| _check_rgb(temp_light->color)
		|| !(temp_light->ratio >= 0. && temp_light->ratio <= 1.))
	{
		if (temp_light->color)
			free (temp_light->color);
		if (temp_light->pos)
			free (temp_light->pos);
		free(*light);
		*light = NULL;
		return (FAILURE);
	}
	return (SUCCESS);
}

t_check	_check_scene(t_scene *settings)
{
	if (!settings->camera || !settings->ambient || !settings->light)
	{
		_free_scene(settings, _LACK_T);
		return (FAILURE);
	}
	return (SUCCESS);
}