/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 17:47:08 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"

int	_key_release(int keycode, t_glob *data)
{
	if (keycode == 'w' || keycode == 's')
		data->kinetic->mv_x = 0;
	if (keycode == 'a' || keycode == 'd')
		data->kinetic->mv_y = 0;
	return (SUCCESS);
}

int	_key_press(int keycode, t_glob *data)
{
	(void)keycode;
	(void)data;
	return (SUCCESS);
}

int	_button_press(int keycode, t_glob *data)
{
	(void)keycode;
	_free_n_exit(data, NULL);
	return (SUCCESS);
}