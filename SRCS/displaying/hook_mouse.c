/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:37:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/25 21:48:22 by tmouche          ###   ########.fr       */
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
	_set_n_getglob(NULL)->window->box = IN;
	return (SUCCESS);
}

int	_focus_out(void)
{
	_set_n_getglob(NULL)->window->box = OUT;
	return (SUCCESS);
}

int	_mouse_mv(int loc_x, int loc_y, t_glob *data)
{
	data->kinetic->cam_rotate->loc_x = loc_x;
	data->kinetic->cam_rotate->loc_y = loc_y;
	if (loc_y == Y_SSIZE / 2)
		data->kinetic->cam_rotate->mv_y = 0;
	else
		data->kinetic->cam_rotate->mv_y = ft_abs(loc_y - Y_SSIZE / 2);
	if (loc_x == X_SSIZE / 2)
		data->kinetic->cam_rotate->mv_x = 0;
	else
		data->kinetic->cam_rotate->mv_x = ft_abs(loc_x - X_SSIZE / 2);
	return (SUCCESS);
}

int	_cross_notify(void)
{
	_free_n_exit(_set_n_getglob(NULL), NULL);
	return (SUCCESS);
}
