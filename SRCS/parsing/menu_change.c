/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:12:31 by tmouche           #+#    #+#             */
/*   Updated: 2024/08/18 15:13:52 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include <unistd.h>

static t_check	_check_coord_buff(char *buff)
{
	int	i;

	if (!buff)
		return (FAILURE);
	i = 0;
	if (buff[i] == '-' || buff[i] == '+')
		++i;
	while (buff[i] >= '0' && buff[i] <= '9')
		++i;
	if (buff[i] == '.')
		++i;
	while (buff[i] >= '0' && buff[i] <= '9')
		++i;
	if (buff[i] != '\n' && buff[i])
		return (FAILURE);
	return (SUCCESS);
}

static t_mstate	_change_coord(float *num, t_coordtype ctype)
{
	char		*buff;
	t_mstate	state;
	float		updated;

	state = CONTINUE;
	if (write(1, "enter the new value : ", 23) == -1)
		return (ERROR);
	buff = get_next_line(0);
	if (!buff)
		return (ERROR);
	if (!ft_strncmp(buff, "QUIT\n", 6))
		return (free(buff), STOP);
	if (!ft_strncmp(buff, "BACK\n", 6))
		return (free(buff), CONTINUE);
	updated = ft_atof(buff);
	if (_check_coord_buff(buff) == FAILURE)
		if (write(1, "unrecognized token, retry\n", 27) == -1)
			state = ERROR;
	free (buff);	
	if (ctype == VEC && !(updated >= -1. && updated <= 1.))
		if (write(1, "value not in range, retry\n", 27) == -1)
			state = ERROR;
	if (state == CONTINUE)
		*num = updated;
	return (state);
}

t_mstate	_change_select(t_coord *vec, t_coordtype type)
{
	char		*buff;
	t_mstate	state;

	state = CONTINUE;
	while (state == CONTINUE)
	{
		if (write(1, "[X - Y - Z] : ", 15) == -1)
			return (ERROR);
		buff = get_next_line(0);
		if (!buff)
			return (ERROR);
		if (!ft_strncmp(buff, "QUIT\n", 6))
			return (free(buff), STOP);
		if (!ft_strncmp(buff, "BACK\n", 6))
			return (free(buff), CONTINUE);
		else if (!ft_strncmp(buff, "X\n", 3))
			state = _change_coord(&vec->x, type);
		else if (!ft_strncmp(buff, "Y\n", 3))
			state = _change_coord(&vec->y, type);
		else if (!ft_strncmp(buff, "Z\n", 3))
			state = _change_coord(&vec->z, type);
		else if (write(1, "unrecognized token, retry\n", 27) == -1)
			state = ERROR;
		free (buff);
	}
	return (state);
}
