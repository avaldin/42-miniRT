/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:57:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/19 21:41:52 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "memory.h"
#include "parsing.h"
#include "structure.h"

t_check	_check_coord(t_coord *coord, float range_min, float range_max)
{
	if (coord && (coord->x >= range_min && coord->x <= range_max)
		&& (coord->y >= range_min && coord->y <= range_max)
		&& (coord->z >= range_min && coord->z <= range_max))
		return (SUCCESS);
	return (FAILURE);	
}

t_check	_check_rgb(t_rgb *colors)
{
	if (colors && (colors->red >= 0 && colors->red <= 255)
		&& (colors->green >= 0 && colors->green <= 255)
		&& (colors->blue >= 0 && colors->blue <= 255))
		return (SUCCESS);
	return (FAILURE);
}

t_rgb	*_set_rgb(char *line)
{
	t_rgb	*color;
	int		*temp[3];
	int		i;
	
	color = _alloc_rgb(0, 0, 0);
	if (!color)
		return (NULL);
	temp[0] = &color->red;
	temp[1] = &color->green;
	temp[2] = &color->blue;
	i = -1;
	while (++i < 3 && line && *line && *line != '\n')
	{
		*temp[i] = ft_atoi(line);
		line = _is_inrange(line, '0', '9');
		if (!line || !*line || *line == '\n')
			return (color);
		if (*line == ',')
			++line;
	}
	return (color);
}

t_coord	*_set_coord(char *line)
{
	t_coord	*vec;
	float	*temp[3];
	int		i;
	
	vec = _alloc_coord(0., 0., 0.);
	if (!vec)
		return (NULL);
	temp[0] = &vec->x;
	temp[1] = &vec->y;
	temp[2] = &vec->z;
	i = -1;
	while (++i < 3 && line && *line && *line != '\n')
	{
		*temp[i] = ft_atof(line);
		if (*line == '-')
			++line;
		line = _is_inrange(line, '0', '9');
		if (*line == '.')
			++line;
		line = _is_inrange(line, '0', '9');
		if (!line || !*line || *line == '\n')
			return (vec);
		if (*line == ',')
			++line;
	}
	return (vec);
}