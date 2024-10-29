/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_change.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:12:31 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/28 14:55:07 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "parsing.h"
#include "libft.h"
#include "calcul.h"
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

static t_mstate	_vec_check_null(t_coord *tk, float *num, float updated)
{
	t_mstate	state;
	float		test;

	state = CONTINUE;
	if ((updated < -1. || updated > 1.))
		state = _strerror(_OUT_RG);
	if (state == CONTINUE && num == &tk->x)
		test = updated + ft_float_abs(tk->y) + ft_float_abs(tk->z);
	else if (state == CONTINUE && num == &tk->y)
		test = ft_float_abs(tk->x) + updated + ft_float_abs(tk->z);
	else if (state == CONTINUE && num == &tk->z)
		test = ft_float_abs(tk->x) + ft_float_abs(tk->y) + updated;
	else
		test = 0.0f;
	if (state == CONTINUE && test == 0.0f)
		state = _strerror(_NULL_VEC);
	return (state);
}

static t_mstate	_change_coord(t_coord *token, float *num, t_coordtype ctype)
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
		state = _strerror(_UNK_T);
	if (state == CONTINUE && ctype == VEC)
		state = _vec_check_null(token, num, ft_float_abs(updated));
	if (state == CONTINUE)
		*num = updated;
	if (state == CONTINUE && ctype == VEC)
		_normalized(token);
	return (free (buff), state);
}

t_mstate	_change_select(t_coord *token, t_coordtype type, t_mstate state)
{
	char		*buff;

	while (state == CONTINUE || state == PASS)
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
			state = _change_coord(token, &token->x, type);
		else if (!ft_strncmp(buff, "Y\n", 3))
			state = _change_coord(token, &token->y, type);
		else if (!ft_strncmp(buff, "Z\n", 3))
			state = _change_coord(token, &token->z, type);
		else
			state = _strerror(_UNK_T);
		free (buff);
	}
	return (state);
}
