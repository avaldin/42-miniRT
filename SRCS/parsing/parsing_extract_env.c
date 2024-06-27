/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extract_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:22:31 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/27 12:51:06 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structure.h"
#include "parsing.h"
#include <stdlib.h>
#include <stdio.h>

t_check	_init_ambient(t_amb **ambient, char *line)
{
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*ambient = malloc(sizeof(t_amb));
	if (!*ambient)
		return (FAILURE);
	(*ambient)->ratio = ft_atof(line);
	if ((*ambient)->ratio > 1 || (*ambient)->ratio < 0)
		return (free((*ambient)), FAILURE);
	line = _is_space(_until_char(line, ' '));
	if (!line)
		return (free((*ambient)), FAILURE);
	(*ambient)->color = _set_rgb(line);
	if (!(*ambient)->color)
		return (free((*ambient)), FAILURE);
	line = _is_space(_until_char(line, ' '));
	if ((line && *line != '\n' && *line) || _check_rgb((*ambient)->color))
		return (free((*ambient)->color), free(*ambient), FAILURE);
	return (SUCCESS);
}

t_check	_init_camera(t_cam **camera, char *line)
{
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*camera = malloc(sizeof(t_cam));
	if (!*camera)
		return (FAILURE);
	(*camera)->pos = _set_coord(line);
	if (!(*camera)->pos)
		return (free(*camera), FAILURE);
	line = _is_space(_until_char(line, ' '));
	(*camera)->vect = _set_coord(line);
	if (!(*camera)->vect)
		return (free((*camera)->pos), free((*camera)->vect), free(*camera), FAILURE);
	line = _is_space(_until_char(line, ' '));
	if (!line)
		return (free((*camera)->pos), free(*camera), FAILURE);
	(*camera)->fov = ft_atoi(line);
	line = _is_space(_until_char(line, ' '));
	if (!((*camera)->fov >= 0 && (*camera)->fov <= 180)
		|| _check_coord((*camera)->pos, -100, 100)					//EN FONCTION DE LA TAILLE DE LA GRILLE ???
		|| _check_coord((*camera)->vect, -1., 1.)
		|| (line && *line != '\n' && *line))
		return (free((*camera)->pos), free((*camera)->vect), free(*camera), 
				FAILURE);
	return (SUCCESS);
}

t_check	_init_light(t_spot **light, char *line)
{
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*light = malloc(sizeof(t_cam));
	if (!*light)
		return (FAILURE);
	(*light)->pos = _set_coord(line);
	if (!(*light)->pos)
		return (free(*light), FAILURE);
	line = _is_space(_until_char(line, ' '));
	(*light)->ratio = ft_atof(line);
	line = _is_space(_until_char(line, ' '));
	if (!line)
		return (free((*light)->pos), free(*light), FAILURE);
	(*light)->color = _set_rgb(line);
	if (!(*light)->color)
		return (free((*light)->pos), free(*light), FAILURE);
	line = _is_space(_until_char(line, ' '));
	if (!((*light)->ratio >= 0. && (*light)->ratio <= 1.)
		|| _check_coord((*light)->pos, -100, 100)					//EN FONCTION DE LA TAILLE DE LA GRILLE ???
		|| _check_rgb((*light)->color) || (line && *line != '\n' && *line))
		return (free((*light)->pos), free((*light)->color), free(*light), 
				FAILURE);
	return (SUCCESS);
}