/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:45:46 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 16:45:53 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "memory.h"
#include "structure.h"
#include <unistd.h>
#include <stdlib.h>

static void	_free_ambient(t_amb *ambient)
{
	if (!ambient)
		return ;
	free (ambient->color);
	free (ambient);
}

static void	_free_camera(t_cam *camera)
{
	if (!camera)
		return ;
	free (camera->pos);
	free (camera->vect);
	free (camera);	
}

static void	_free_light(t_spot *light)
{
	if (!light)
		return ;
	free (light->color);
	free (light->pos);
	free (light);
}

void	_free_scene(t_scene *scene, char *err)
{
	_free_sphere(scene->sphere);
	_free_plane(scene->plane);
	_free_cylinder(scene->cylinder);
	_free_ambient(scene->ambient);
	_free_camera(scene->camera);
	_free_light(scene->light);
	if (err)
		write (2, err, ft_strlen(err, 0));
	free (scene);
}