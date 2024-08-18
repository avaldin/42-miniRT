/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 04:36:45 by thibaud           #+#    #+#             */
/*   Updated: 2024/08/18 09:53:38 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static t_mstate	_menu_select(t_scene *scene)
{
	char		*buff;
	t_mstate	state;

	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[CYLINDER - SPHERE - PLANE] : ", 30) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "CYLINDER\n", 11))
			state = _select_cylinder(scene->cylinder);
		else if (!ft_strncmp(buff, "SPHERE\n", 8))
			state = _select_cylinder(scene->cylinder);
		else if (!ft_strncmp(buff, "PLANE\n", 7))
			state = _select_cylinder(scene->cylinder);
		else if (!ft_strncmp(buff, "QUIT\n", 6))
			state = STOP;
		else if (!ft_strncmp(buff, "BACK\n", 6))
			state = CONTINUE;
		else if (write(1, "token not known, retry\n", 24) == -1)
			state = ERROR;
		free (buff);
	}
	return (state);
}

t_check	_menu(t_glob *data)
{
	char		*buff;
	t_check		res;
	t_mstate	state;
	
	res = FAILURE;
	if (write(1, "[MENU]\nQUIT to exit menu | BACK to return to the precedent screen\n", 67) == -1)
		return (FAILURE);
	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[QUIT - SELECT] : ", 19) == -1)
			return (FAILURE);
		buff = get_next_line(0);
		if (!buff)
			return (FAILURE);
		if (!ft_strncmp(buff, "QUIT\n", 6) || !ft_strncmp(buff, "BACK\n", 6))
			state = STOP;
		else if (!ft_strncmp(buff, "SELECT\n", 8))
			state = _menu_select(data->scene);
		else if (write(1, "token not known, retry\n", 24) == -1)
			state = ERROR;
		free (buff);
	}
	data->window->interf = SCENE;
	return (res);
}
