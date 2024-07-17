/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_env_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:22:31 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/17 02:46:57 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structure.h"
#include "parsing.h"
#include <stdlib.h>

t_check	_init_ambient(t_amb **ambient, char *line)
{
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*ambient = malloc(sizeof(t_amb));
	if (!*ambient)
		return (FAILURE);
	(*ambient)->ratio = ft_atof(line);
	line = _is_space(_until_char(line, ' '));
	(*ambient)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_ambient(ambient, line));
}

t_check	_init_camera(t_cam **camera, char *line)
{
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*camera = malloc(sizeof(t_cam));
	if (!*camera)
		return (FAILURE);
	(*camera)->mvt = _set_coord(NULL);
	(*camera)->pos = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*camera)->vect = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*camera)->fov = ft_atoi(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_camera(camera, line));
}

t_check	_init_light(t_spot **light, char *line)
{
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*light = malloc(sizeof(t_spot));
	if (!*light)
		return (FAILURE);
	(*light)->pos = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*light)->ratio = ft_atof(line);
	line = _is_space(_until_char(line, ' '));
	(*light)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_light(light, line));
}