/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_obj_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:41:20 by thibaud           #+#    #+#             */
/*   Updated: 2024/06/30 15:42:45 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>

t_check	_sphere_table(t_sphere ***map, char *line)
{
	t_sphere	**new;
	int			i;
	
	i = 0;
	while (*map && *map[i])
		++i;
	new = ft_calloc(sizeof(t_sphere), i + 2);
	if (!new)
		return (FAILURE);
	i = 0;
	while (*map && *map[i])
	{
		new[i] = *map[i];
		++i;
	}
	if (_init_sphere(&new[i], line) == FAILURE)
		return (FAILURE);
	free (*map);
	*map = new;
	return (SUCCESS);		
}

t_check	_plane_table(t_plane ***map, char *line)
{
	t_plane	**new;
	int			i;
	
	i = 0;
	while (*map && *map[i])
		++i;
	new = ft_calloc(sizeof(t_plane), i + 2);
	if (!new)
		return (FAILURE);
	i = 0;
	while (*map && *map[i])
	{
		new[i] = *map[i];
		++i;
	}
	if (_init_plane(&new[i], line) == FAILURE)
		return (FAILURE);
	free (*map);
	*map = new;
	return (SUCCESS);		
}

t_check	_cylinder_table(t_cylinder ***map, char *line)
{
	t_cylinder	**new;
	int			i;
	
	i = 0;
	while (*map && *map[i])
		++i;
	new = ft_calloc(sizeof(t_cylinder), i + 2);
	if (!new)
		return (FAILURE);
	i = 0;
	while (*map && *map[i])
	{
		new[i] = *map[i];
		++i;
	}
	if (_init_cylinder(&new[i], line) == FAILURE)
		return (FAILURE);
	free (*map);
	*map = new;
	return (SUCCESS);		
}
