/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obj_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:40:51 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/28 12:06:09 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory.h>

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>
#include "calcul.h"

t_check	_init_sphere(t_sphere **sphere, char *line)
{
	line = _is_space(&line[3]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*sphere = malloc(sizeof(t_sphere));
	if (!*sphere)
		return (FAILURE);
	ft_memset(*sphere, 0, sizeof(t_sphere));
	(*sphere)->pos = _set_coord(line);
	(*sphere)->r_pos = _alloc_coord(0, 0, 0);
	line = _is_space(_until_char(line, ' '));
	(*sphere)->radius = ft_atof(line) / 2;
	line = _is_space(_until_char(line, ' '));
	(*sphere)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_sphere(sphere, line));
}

t_check	_init_plane(t_plane **plane, char *line)
{
	line = _is_space(&line[3]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*plane = malloc(sizeof(t_plane));
	if (!*plane)
		return (FAILURE);
	ft_memset(*plane, 0, sizeof(t_plane));
	(*plane)->pos = _set_coord(line);
	(*plane)->r_pos = _alloc_coord(0, 0, 0);
	line = _is_space(_until_char(line, ' '));
	(*plane)->vect = _set_coord(line);
	_normalized((*plane)->vect);
	(*plane)->r_vect = _alloc_coord(0, 0, 0);
	line = _is_space(_until_char(line, ' '));
	(*plane)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_plane(plane, line));
}

t_check	_init_cylinder(t_cylinder **cylinder, char *line)
{
	line = _is_space(&line[3]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*cylinder = malloc(sizeof(t_cylinder));
	if (!*cylinder)
		return (FAILURE);
	ft_memset(*cylinder, 0, sizeof(t_cylinder));
	(*cylinder)->pos = _set_coord(line);
	(*cylinder)->r_pos = _alloc_coord(0, 0, 0);
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->vect = _set_coord(line);
	_normalized((*cylinder)->vect);
	(*cylinder)->r_vect = _alloc_coord(0, 0, 0);
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->radius = ft_atof(line) / 2;
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->height = ft_atof(line);
	line = _is_space(_until_char(line, ' '));
	(*cylinder)->color = _set_rgb(line);
	line = _is_space(_until_char(line, ' '));
	return (_check_cylinder(cylinder, line));
}
