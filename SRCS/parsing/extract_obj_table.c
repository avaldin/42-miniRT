/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obj_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:41:20 by thibaud           #+#    #+#             */
/*   Updated: 2024/10/03 13:13:47 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>

t_check	_sphere_table(t_scene *scene, char *line)
{
	t_sphere	**new;
	int			i;

	i = 0;
	while (scene->sphere && scene->sphere[i])
		++i;
	new = ft_calloc(sizeof(t_sphere), i + 2);
	if (!new)
		return (FAILURE);
	i = 0;
	while (scene->sphere && scene->sphere[i])
	{
		new[i] = scene->sphere[i];
		++i;
	}
	if (_init_sphere(&new[i], line) == FAILURE)
		return (free(new), FAILURE);
	if (scene->sphere)
		free (scene->sphere);
	scene->sphere = new;
	return (SUCCESS);
}

t_check	_plane_table(t_scene *scene, char *line)
{
	t_plane	**new;
	int		i;

	i = 0;
	while (scene->plane && scene->plane[i])
		++i;
	new = ft_calloc(sizeof(t_plane), i + 2);
	if (!new)
		return (FAILURE);
	i = 0;
	while (scene->plane && scene->plane[i])
	{
		new[i] = scene->plane[i];
		++i;
	}
	if (_init_plane(&new[i], line) == FAILURE)
		return (free(new), FAILURE);
	if (scene->plane)
		free (scene->plane);
	scene->plane = new;
	return (SUCCESS);
}

t_check	_cylinder_table(t_scene *scene, char *line)
{
	t_cylinder	**new;
	int			i;

	i = 0;
	while (scene->cylinder && scene->cylinder[i])
		++i;
	new = ft_calloc(sizeof(t_cylinder), i + 2);
	if (!new)
		return (FAILURE);
	i = 0;
	while (scene->cylinder && scene->cylinder[i])
	{
		new[i] = scene->cylinder[i];
		++i;
	}
	if (_init_cylinder(&new[i], line) == FAILURE)
		return (free(new), FAILURE);
	if (scene->cylinder)
		free (scene->cylinder);
	scene->cylinder = new;
	return (SUCCESS);
}
