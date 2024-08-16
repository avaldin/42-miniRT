/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 04:36:45 by thibaud           #+#    #+#             */
/*   Updated: 2024/08/16 05:52:24 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

t_check	_select_cylinder(t_cylinder **cylinder)
{
	char	*buff;
	int			i;
	ssize_t		n_cyl;

	if (!cylinder)
	{
		if (write(1, "token is not existing in the current scene\n", 41) == -1)
			return (FAILURE);
		return (SUCCESS);
	}
	if (write(1, "N° of the cylinder asked : ", 29) == -1)
		return (FAILURE);
	buff = get_next_line(0);
	if (!buff)
		return (FAILURE);
	n_cyl = ft_atol(buff);
	i = 0;
	while (cylinder[i] && i < n_cyl - 1)
		++i;
	if (!cylinder[i])
	{
		if (write(1, "no token at this id\n", 21) == -1)
			return (FAILURE);
		return (SUCCESS);
	}
	else
		printf("trouvé\n");
	return (SUCCESS);
}

t_check _menu_select(t_scene *scene)
{
	char	*buff;

	if (write(1, "CYLINDER - SPHERE - PLANE] : ", 30) == -1)
		return (FAILURE);
	buff = get_next_line(0);
	if (!ft_strncmp(buff, "CYLINDER\n", 11))
		_select_cylinder(scene->cylinder);
	else if (!ft_strncmp(buff, "SPHERE\n", 8))
		_select_cylinder(scene->cylinder);
	else if (!ft_strncmp(buff, "PLANE\n", 7))
		_select_cylinder(scene->cylinder);
	else if (!buff || write(1, "token not known\n", 14) == -1)
		return (FAILURE);
	free (buff);
	return (SUCCESS);
}

t_check	_menu(t_glob *data)
{
	char	*buff;
	t_check		res;
	
	res = FAILURE;
	if (write(1, "[MENU]\n\n", 9) == -1)
		return (FAILURE);
	if (write(1, "[QUIT - SELECT] : ", 19) == -1)
		return (FAILURE);
	buff = get_next_line(0);
	if (!ft_strncmp(buff, "QUIT\n", 6))
	{
		data->menu = SCENE;
		res = SUCCESS;
	}
	if (!ft_strncmp(buff, "SELECT\n", 8))
		_menu_select(data->scene);
	return (res); //hardquit
}
