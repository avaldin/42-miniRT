/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 04:36:45 by thibaud           #+#    #+#             */
/*   Updated: 2024/10/02 18:48:57 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>

static t_mstate	_menu_select(t_scene *scene, t_mstate state)
{
	char		*buff;

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
			state = _select_sphere(scene->sphere);
		else if (!ft_strncmp(buff, "PLANE\n", 7))
			state = _select_plane(scene->plane);
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

t_mstate	_menu(t_glob *data)
{
	char		*buff;
	t_mstate	state;

	if (write(1, "[MENU]\nQUIT to exit menu | "
			"BACK to return to the precedent screen\n", 67) == -1)
		return (ERROR);
	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[QUIT - SELECT] : ", 19) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "QUIT\n", 6) || !ft_strncmp(buff, "BACK\n", 6))
			state = STOP;
		else if (!ft_strncmp(buff, "SELECT\n", 8))
			state = _menu_select(data->scene, CONTINUE);
		else if (write(1, "token not known, retry\n", 24) == -1)
			state = ERROR;
		free (buff);
	}
	data->window->interf = SCENE;
	return (state);
}
