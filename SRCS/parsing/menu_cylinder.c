/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:46:27 by tmouche           #+#    #+#             */
/*   Updated: 2024/08/18 11:42:42 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>

static t_mstate	_change_coord(float *num, t_coordtype ctype)
{
	char		*buff;
	t_mstate	state;
	float		updated;

	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "enter the new value : ", 23) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!ft_strncmp(buff, "QUIT\n", 6))
			state = STOP;
		if (!ft_strncmp(buff, "BACK\n", 6))
			return (free(buff), CONTINUE);
		updated = ft_atof(buff);
		if (state == CONTINUE/* && _check_coord_buff(buff) == SUCCESS*/)
		{
			if (ctype == VEC && !(updated >= -1. && updated <= 1.))
			{
				if (write(1, "value not in range, retry\n", 27) == -1)
					state = ERROR;
			}
			else
				*num = updated;
		}
		else if (!buff || write(1, "unrecognized token, retry\n", 21) == -1)
			state = ERROR;
		if (buff)
			free (buff);	
	}
	return (state);
}

static t_mstate	_change_select(t_coord *vec, t_coordtype type)
{
	char		*buff;
	t_mstate	state;

	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[X - Y - Z] : ", 15) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!ft_strncmp(buff, "QUIT\n", 6))
			state = STOP;
		if (!ft_strncmp(buff, "BACK\n", 6))
			return (free(buff), CONTINUE);
		else if (!ft_strncmp(buff, "X\n", 3))
			state = _change_coord(&vec->x, type);
		else if (!ft_strncmp(buff, "Y\n", 3))
			state = _change_coord(&vec->y, type);
		else if (!ft_strncmp(buff, "Z\n", 3))
			state = _change_coord(&vec->z, type);
		else if (!buff || write(1, "unrecognized token, retry\n", 21) == -1)
			state = ERROR;
		if (buff)
			free (buff);
	}
	return (state);
}

static t_mstate	_cylinder_change(t_cylinder *cylinder)
{
	char		*buff;
	t_mstate	state;

	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[POSITION - VECTOR] : ", 23) == - 1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "QUIT\n", 6) || !ft_strncmp(buff, "BACK\n", 6))
			state = STOP;
		else if (!ft_strncmp(buff, "POSITION\n", 10))
			state = _change_select(cylinder->pos, POS);
		else if (!ft_strncmp(buff, "VECTOR\n", 8))
			state = _change_select(cylinder->vect, VEC);
		else if (write(1, "unrecognized token, retry\n", 21) == -1)
			return (ERROR);
		free (buff);
	}
	return (state);
}

t_mstate	_select_cylinder(t_cylinder **cylinder)
{
	char		*buff;
	int			i;
	ssize_t		n_cyl;
	t_mstate	state;

	state = CONTINUE;
	if (!cylinder && write(1, "token is not existing in the current scene\n", 41) == -1)
		state = ERROR;
	while (cylinder && state == CONTINUE)
	{	
		if (write(1, "N° of the cylinder asked : ", 29) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "QUIT\n", 6) || !ft_strncmp(buff, "BACK\n", 6))
			state = STOP;
		n_cyl = ft_atol(buff);
		free (buff);
		i = 0;
		while (cylinder[i] && i < n_cyl - 1)
			++i;
		if (n_cyl > 0 && cylinder[i])
			state = _cylinder_change(cylinder[i]);
		else if (write(1, "unrecognized id, retry\n", 21) == -1)
			return (ERROR);
	}
	return (state);
}