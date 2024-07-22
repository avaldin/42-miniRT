/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:37:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/22 20:03:12 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "structure.h"
#include "displaying.h"
#include "calcul.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

int _focus_in(void)
{
	_set_n_getglob(NULL)->window->box = IN;
	return (SUCCESS);
}

int _focus_out(void)
{
	_set_n_getglob(NULL)->window->box = OUT;
	return (SUCCESS);
}

int _button_release(void)
{
	t_glob	*data;

	data = _set_n_getglob(NULL); ;
	data->kinetic->cam_rotate->s_input = OUT;
	return (SUCCESS);
}

int _button_press(void)
{
	t_glob	*data;

	data = _set_n_getglob(NULL); 
	data->kinetic->cam_rotate->s_input = IN;
	return (SUCCESS);
}

int _mouse_mv(int loc_x, int loc_y, t_glob *data)
{	
	if (data->kinetic->cam_rotate->s_input == OUT)
		return (FAILURE);
	if (loc_y == Y_SSIZE / 2)
		data->kinetic->cam_moov->mv_y = 0;
	else if (loc_y < Y_SSIZE)
		data->kinetic->cam_moov->mv_y = 1;
	else
		data->kinetic->cam_moov->mv_y = -1;
	if (loc_x == X_SSIZE / 2)
		data->kinetic->cam_moov->mv_x = 0;
	else if (loc_x < X_SSIZE)
		data->kinetic->cam_moov->mv_x = -1;
	else
		data->kinetic->cam_moov->mv_y = 1;
	return (SUCCESS);
}

int _cross_notify(void)
{
	_free_n_exit(_set_n_getglob(NULL), NULL);
	return (SUCCESS);
}
