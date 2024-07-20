/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:37:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/20 03:45:18 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "structure.h"
#include "displaying.h"
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
	data->kinetic->cam_rotate->last_x = -1;
	data->kinetic->cam_rotate->last_y = -1;
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
	if (data->kinetic->cam_rotate->last_x == -1)
	{
		data->kinetic->cam_rotate->last_x = loc_x;
		data->kinetic->cam_rotate->last_y = loc_y;
	}
	data->scene->camera->vect->z += _change_cam_direction(data->kinetic->cam_rotate->last_x, loc_x);
	data->scene->camera->vect->y += _change_cam_direction(data->kinetic->cam_rotate->last_y, loc_y);
	return (SUCCESS);
}

int _cross_notify(void)
{
	_free_n_exit(_set_n_getglob(NULL), NULL);
	return (SUCCESS);
}
