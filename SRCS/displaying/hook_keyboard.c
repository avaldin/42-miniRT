/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:37:33 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/20 01:30:50 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

int	_key_release(int keycode, t_glob *data)
{
	if (keycode == 'w' || keycode == 's')
		data->kinetic->cam_moov->mv_x = 0;
	if (keycode == 'a' || keycode == 'd')
		data->kinetic->cam_moov->mv_y = 0;
	return (SUCCESS);
}

int	_key_press(int keycode, t_glob *data)
{
	if (keycode == 'w')
		data->kinetic->cam_moov->mv_x = 0.2;
	if (keycode == 's')
		data->kinetic->cam_moov->mv_x = -0.2;
	if (keycode == 'a')
		data->kinetic->cam_moov->mv_y = 0.2;
	if (keycode == 'd')
		data->kinetic->cam_moov->mv_y = -0.2;
	return (SUCCESS);
}
