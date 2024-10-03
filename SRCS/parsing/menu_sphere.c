/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:18:13 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/02 18:53:26 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>

static t_mstate	_sphere_change(t_sphere *sphere)
{
	char		*buff;
	t_mstate	state;

	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[POSITION] : ", 14) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "QUIT\n", 6))
			return (free(buff), STOP);
		if (!ft_strncmp(buff, "BACK\n", 6))
			return (free(buff), CONTINUE);
		else if (!ft_strncmp(buff, "POSITION\n", 10))
			state = _change_select(sphere->pos, POS, CONTINUE);
		else if (write(1, "unrecognized token, retry\n", 27) == -1)
			state = ERROR;
		free (buff);
	}
	return (state);
}

static t_mstate	_sphere_choice(t_sphere **sphere, t_mstate state)
{
	char		*buff;
	ssize_t		n_cyl;
	int			i;

	if (write(1, "N° of the sphere asked : ", 29) == -1)
		return (ERROR);
	buff = get_next_line(0);
	if (!buff)
		return (ERROR);
	if (!ft_strncmp(buff, "QUIT\n", 6))
		return (free(buff), STOP);
	if (!ft_strncmp(buff, "BACK\n", 6))
		return (free(buff), CONTINUE);
	n_cyl = ft_atol(buff);
	free (buff);
	i = 0;
	while (sphere[i] && i < n_cyl - 1)
		++i;
	if (n_cyl > 0 && sphere[i])
		state = _sphere_change(sphere[i]);
	else if (write(1, "unrecognized id, retry\n", 24) == -1)
		state = ERROR;
	return (state);
}

t_mstate	_select_sphere(t_sphere **sphere)
{
	t_mstate	state;

	state = CONTINUE;
	if (!sphere
		&& write(1, "token is not existing in the current scene\n", 44) == -1)
		state = ERROR;
	while (sphere && state == CONTINUE)
		state = _sphere_choice(sphere, state);
	return (state);
}
