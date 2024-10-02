/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:37:33 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/02 17:04:33 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"

int	_key_release(int keycode, t_glob *data)
{
	if (keycode == 'w' || keycode == 's')
		data->kinetic->cam_moov->mv_z = 0;
	if (keycode == 'a' || keycode == 'd')
		data->kinetic->cam_moov->mv_x = 0;
	if (keycode == ' ' || keycode == 65505)
		data->kinetic->cam_moov->mv_y = 0;
	return (SUCCESS);
}

int	_key_press(int keycode, t_glob *data)
{
	if (keycode == 'w')
		data->kinetic->cam_moov->mv_z = 1.;
	else if (keycode == 's')
		data->kinetic->cam_moov->mv_z = -1.;
	else if (keycode == 'a')
		data->kinetic->cam_moov->mv_x = 1.;
	else if (keycode == 'd')
		data->kinetic->cam_moov->mv_x = -1.;
	else if (keycode == ' ')
		data->kinetic->cam_moov->mv_y = 1.;
	else if (keycode == 65505)
		data->kinetic->cam_moov->mv_y = -1.;
	else if (keycode == 'm' && data->window->interf == SCENE)
		data->window->interf = MENU;
	else if (keycode == 65307)
		_free_n_exit(data, NULL);
	return (SUCCESS);
}
