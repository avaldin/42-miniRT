/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:37:47 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/21 04:31:38 by tmouche          ###   ########.fr       */
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
	t_coord axis;
	float	angle;
	
	if (data->kinetic->cam_rotate->s_input == OUT)
		return (FAILURE);
	if (data->kinetic->cam_rotate->last_x == -1)
	{
		data->kinetic->cam_rotate->last_x = loc_x;
		data->kinetic->cam_rotate->last_y = loc_y;
	}
	axis.x = 0;
	axis.y = 1;
	axis.z = 0;
	angle = acos((ft_abs(data->kinetic->cam_rotate->last_x - X_SSIZE / 2) * ft_abs(loc_x - X_SSIZE / 2) + ft_abs(data->kinetic->cam_rotate->last_y - Y_SSIZE / 2) * ft_abs(loc_y - Y_SSIZE / 2))
				/ (sqrt(pow(data->kinetic->cam_rotate->last_x - X_SSIZE / 2, 2) + pow(data->kinetic->cam_rotate->last_y - Y_SSIZE / 2, 2)) *
				sqrt(pow(loc_x - X_SSIZE / 2, 2) + pow(loc_y - Y_SSIZE / 2, 2))));
	printf("angle : %f\n", angle);
	_rotate_vec_3d(data->scene->camera->vect, &axis, angle);
	// _rotate_vec_2d(&data->scene->camera->vect->x, &data->scene->camera->vect->y, angle);
	return (SUCCESS);
}

int _cross_notify(void)
{
	_free_n_exit(_set_n_getglob(NULL), NULL);
	return (SUCCESS);
}
