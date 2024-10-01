/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_env_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:22:31 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/01 13:38:04 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>
#include "libft.h"
#include "calcul.h"
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
	static t_coord	r_coord;
	
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*camera = malloc(sizeof(t_cam));
	if (!*camera)
		return (FAILURE);
	(*camera)->pos = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*camera)->vect = _set_coord(line);
	_normalized((*camera)->vect);
	line = _is_space(_until_char(line, ' '));
	(*camera)->fov = ft_atoi(line);
	(*camera)->fov = (*camera)->fov * _PI / 180.0f;
	line = _is_space(_until_char(line, ' '));
	(*camera)->r_pos = &r_coord;
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
	(*light)->r_pos = _alloc_coord(0, 0, 0);
	line = _is_space(_until_char(line, ' '));
	(*light)->ratio = ft_atof(line);
	line = _is_space(_until_char(line, ' '));
	(*light)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_light(light, line));
}
