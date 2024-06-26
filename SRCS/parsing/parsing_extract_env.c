/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extract_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:22:31 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/26 20:55:02 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structure.h"
#include "parsing.h"
#include <stdlib.h>
#include <stdio.h>

t_check	_init_ambient(t_amb **ambient, char *line)
{
	*ambient = malloc(sizeof(t_amb));
	if (!*ambient)
		return (FAILURE);
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (free((*ambient)), FAILURE);
	(*ambient)->ratio = ft_atof(line);
	if ((*ambient)->ratio > 1 || (*ambient)->ratio < 0)
		return (free((*ambient)), FAILURE);
	line = _until_char(line, ' ');
	line = _is_space(line);
	if (!line)
		return (free((*ambient)), FAILURE);
	(*ambient)->color = _set_rgb(line);
	if (!(*ambient)->color)
		return (free((*ambient)), FAILURE);
	if (_check_rgb((*ambient)->color) == FAILURE)
		return (free((*ambient)), FAILURE);
	line = _until_char(line, ' ');
	line = _is_space(line);
	if (line && *line != '\n' && *line)
		return (free((*ambient)), FAILURE);
	return (SUCCESS);
}

t_check	_init_camera(t_cam **camera, char *line)
{
	*camera = malloc(sizeof(t_cam));
	if (!*camera)
		return (FAILURE);
	line = _is_space(&line[2]);
	if (check_line(line) == FAILURE)
		return (free(*camera), FAILURE);
	
	return (SUCCESS);
}

// t_check	_init_light(t_spot *light, char *line)
// {
	
// }