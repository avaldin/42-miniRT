/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:15:27 by tmouche           #+#    #+#             */
/*   Updated: 2024/08/20 03:54:38 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>

static t_mstate	_plane_change(t_plane *plane)
{
	char		*buff;
	t_mstate	state;

	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[POSITION - VECTOR] : ", 23) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "QUIT\n", 6))
			return (free(buff), STOP);
		if (!ft_strncmp(buff, "BACK\n", 6))
			return (free(buff), CONTINUE);
		else if (!ft_strncmp(buff, "POSITION\n", 10))
			state = _change_select(plane->pos, POS, CONTINUE);
		else if (!ft_strncmp(buff, "VECTOR\n", 8))
			state = _change_select(plane->vect, VEC, CONTINUE);
		else if (write(1, "unrecognized token, retry\n", 27) == -1)
			state = ERROR;
		free (buff);
	}
	return (state);
}

static t_mstate	_plane_choice(t_plane **plane, t_check state)
{
	char		*buff;
	ssize_t		n_cyl;
	int			i;

	if (write(1, "N° of the plane asked : ", 29) == -1)
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
	while (plane[i] && i < n_cyl - 1)
		++i;
	if (n_cyl > 0 && plane[i])
		state = _plane_change(plane[i]);
	else if (write(1, "unrecognized id, retry\n", 24) == -1)
		state = ERROR;
	return (state);
}

t_mstate	_select_plane(t_plane **plane)
{
	t_mstate	state;

	state = CONTINUE;
	if (!plane
		&& write(1, "token is not existing in the current scene\n", 44) == -1)
		state = ERROR;
	while (plane && state == CONTINUE)
		state = _plane_choice(plane, state);
	return (state);
}
