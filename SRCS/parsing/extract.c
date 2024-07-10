/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:11:58 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/07 01:30:49 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

static char **_read_file(int fd)
{
	char	**res;
	char	**t_map;
	char	*t_str;
	
	res = NULL;
	t_map = NULL;
	while (42)
	{
		errno = 0;
		t_str = get_next_line(fd);
		if (!t_str && errno)
			return (_freetab(res), perror(NULL), NULL);
		else if (!t_str)
			break ;
		if (ft_strfull(t_str, 9, 13))
		{
			t_map = ft_stradd(res, t_str);
			if (!t_map)
				return (_freetab(res), free (t_str), perror(NULL), NULL);
		}
		else
			free (t_str);
		res = t_map;
	}
	return (t_map);
}

static void	_init_scene(t_scene *scene)
{
	// static t_rescam	reset;
	static t_coord	axis;
	static float	var[4] = {0., 0., 0., 0.};
	
	// reset.cos_x = 0.;
	// reset.cos_y = 0.;
	// reset.sin_x = 0.;
	// reset.sin_y = 0.;
	axis.x = 0.;
	axis.y = 0.;
	axis.z = 0.;
	scene->axis = &axis;
	// scene->var = &reset;
	scene->var = var;
	scene->ambient = NULL;
	scene->light = NULL;
	scene->camera = NULL;
	scene->data = NULL;
	scene->cylinder = NULL;
	scene->sphere = NULL;
	scene->plane = NULL;
}

static t_check	_data_loader(t_scene *scene, char *line)
{
	t_check	res;

	res = FAILURE;
	if (!ft_strncmp(line, "A ", 2) && !scene->ambient)
		res = _init_ambient(&scene->ambient ,line);
	else if (!ft_strncmp(line, "C ", 2) && !scene->camera)
		res = _init_camera(&scene->camera, line);
	else if (!ft_strncmp(line, "L ", 2) && !scene->light)
		res = _init_light(&scene->light, line);
	else if (!ft_strncmp(line, "sp ", 3))
		res = _sphere_table(&scene->sphere, line);
	else if (!ft_strncmp(line, "pl ", 3))
		res = _plane_table(&scene->plane, line);
	else if (!ft_strncmp(line, "cy ", 3))
		res = _cylinder_table(&scene->cylinder, line);
	return (res);
}

static t_scene *_pars_line(char **data)
{
	t_scene	*scene;
	char	*temp;
	int		i;

	i = 0;
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	_init_scene(scene);
	while (data[i])
	{
		temp = _is_space(data[i]);
		if (temp && _data_loader(scene, temp) == FAILURE)
			return (_free_scene(scene, _NOK_ID), NULL);
		++i;
	}
	return (scene);	
}

t_scene	*_extract_data(char	*path_file)
{
	t_scene	*settings;
	char	**data;
	int		fd;

	fd = open(path_file, O_RDONLY);
	if (fd < 0)
		return (perror(NULL), NULL);
	data = _read_file(fd);
	close (fd);
	if (!data)
		return (NULL);
	settings = _pars_line(data);
	if (!settings)
		return (NULL);
	_freetab(data);
	settings->x_screen = X_SCREEN_SIZE;
	settings->y_screen = Y_SCREEN_SIZE;
	return (settings);
}