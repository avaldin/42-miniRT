/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extract_obj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:40:51 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/27 18:53:43 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structure.h"
#include "parsing.h"
#include <stdlib.h>

t_check	_init_plane(t_plane **plane, char *line)
{
	line = _is_space(&line[3]);
	if (check_line(line) == FAILURE)
		return (FAILURE);
	*plane = malloc(sizeof(t_plane));
	if (!*plane)
		return (FAILURE);
	(*plane)->pos = _set_coord(line);
	if (!(*plane)->pos)
		return (free (*plane), FAILURE);
	line = _is_space(_until_char(line, ' '));
	

		
	return (SUCCESS);
}