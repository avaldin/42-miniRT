/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:46:27 by tmouche           #+#    #+#             */
/*   Updated: 2024/08/20 03:50:13 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>

static t_mstate	_cylinder_change(t_cylinder *cylinder)
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
			state = _change_select(cylinder->pos, POS, CONTINUE);
		else if (!ft_strncmp(buff, "VECTOR\n", 8))
			state = _change_select(cylinder->vect, VEC, CONTINUE);
		else if (write(1, "unrecognized token, retry\n", 27) == -1)
			state = ERROR;
		free (buff);
	}
	return (state);
}

static t_mstate	_cylinder_choice(t_cylinder **cylinder, t_check state)
{
	char		*buff;
	ssize_t		n_cyl;
	int			i;

	if (write(1, "N° of the cylinder asked : ", 29) == -1)
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
	while (cylinder[i] && i < n_cyl - 1)
		++i;
	if (n_cyl > 0 && cylinder[i])
		state = _cylinder_change(cylinder[i]);
	else if (write(1, "unrecognized id, retry\n", 24) == -1)
		state = ERROR;
	return (state);
}

t_mstate	_select_cylinder(t_cylinder **cylinder)
{
	t_mstate	state;

	state = CONTINUE;
	if (!cylinder
		&& write(1, "token is not existing in the current scene\n", 44) == -1)
		state = ERROR;
	while (cylinder && state == CONTINUE)
		state = _cylinder_choice(cylinder, state);
	return (state);
}
