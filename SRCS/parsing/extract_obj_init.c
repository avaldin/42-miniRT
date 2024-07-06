/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obj_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:40:51 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/05 14:04:57 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>

t_check	_init_sphere(t_sphere **sphere, char *line)
{	
	line = _is_space(&line[3]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*sphere = malloc(sizeof(t_sphere));
	if (!*sphere)
		return (FAILURE);
	(*sphere)->pos = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*sphere)->radius = ft_atof(line) / 2;
	line = _is_space(_until_char(line, ' '));
	(*sphere)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_sphere(*sphere, line));
}

t_check	_init_plane(t_plane **plane, char *line)
{
	line = _is_space(&line[3]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*plane = malloc(sizeof(t_plane));
	if (!*plane)
		return (FAILURE);
	(*plane)->pos = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*plane)->vect = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*plane)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_plane(*plane, line));
}

t_check	_init_cylinder(t_cylinder **cylinder, char *line)
{
	line = _is_space(&line[3]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*cylinder = malloc(sizeof(t_cylinder));
	if (!*cylinder)
		return (FAILURE);
	(*cylinder)->pos = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->vect = _set_coord(line);
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->radius = ft_atof(line) / 2;
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->height = ft_atof(line);
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_cylinder(*cylinder, line));
}