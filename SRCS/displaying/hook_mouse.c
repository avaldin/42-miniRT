/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:37:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/21 17:03:28 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "structure.h"
#include "displaying.h"
#include "calcul.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>
#include "../../include/minilibx-linux/mlx.h"

int	_focus_in(void)
{
	if (_set_n_getglob(NULL)->scene->state == -1)
		return (SUCCESS);
	_set_n_getglob(NULL)->window->box = IN;
	return (SUCCESS);
}

int	_focus_out(void)
{
	if (_set_n_getglob(NULL)->scene->state == -1)
		return (SUCCESS);
	_set_n_getglob(NULL)->window->box = OUT;
	return (SUCCESS);
}

int	_mouse_mv(int loc_x, int loc_y, t_glob *data)
{
	if (data->scene->state == -1)
		return (SUCCESS);
	data->kinetic->cam_rotate->loc_x = loc_x;
	data->kinetic->cam_rotate->loc_y = loc_y;
	if (loc_y == Y_SSIZE / 2)
		data->kinetic->cam_rotate->mv_y = 0;
	else
		data->kinetic->cam_rotate->mv_y = ft_int_abs(loc_y - Y_SSIZE / 2);
	if (loc_x == X_SSIZE / 2)
		data->kinetic->cam_rotate->mv_x = 0;
	else
		data->kinetic->cam_rotate->mv_x = ft_int_abs(loc_x - X_SSIZE / 2);
	return (SUCCESS);
}

int	_cross_notify(void)
{
	_free_n_exit(_set_n_getglob(NULL), NULL);
	return (SUCCESS);
}
