/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:18:13 by tmouche           #+#    #+#             */
/*   Updated: 2024/08/18 15:21:48 by tmouche          ###   ########.fr       */
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
		if (write(1, "[POSITION] : ", 14) == - 1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "QUIT\n", 6))
			return (free(buff), STOP);
		if (!ft_strncmp(buff, "BACK\n", 6))
			return (free(buff), CONTINUE);
		else if (!ft_strncmp(buff, "POSITION\n", 10))
			state = _change_select(sphere->pos, POS);
		else if (write(1, "unrecognized token, retry\n", 27) == -1)
			state = ERROR;
		free (buff);
	}
	return (state);
}

t_mstate	_select_sphere(t_sphere **sphere)
{
	char		*buff;
	int			i;
	ssize_t		n_cyl;
	t_mstate	state;

	state = CONTINUE;
	if (!sphere && write(1, "token is not existing in the current scene\n", 44) == -1)
		state = ERROR;
	while (sphere && state == CONTINUE)
	{	
		if (write(1, "N° of the sphere asked : ", 27) == -1)
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
	}
	return (state);
}