/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 18:58:51 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "moovement.h"
#include "memory.h"
#include "calcul.h"
#include "../include/minilibx-linux/mlx.h"

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
	if (keycode == 'w')
		data->kinetic->mv_x = 0.2;
	if (keycode == 's')
		data->kinetic->mv_x = -0.2;
	if (keycode == 'a')
		data->kinetic->mv_y = 0.2;
	if (keycode == 'd')
		data->kinetic->mv_y = -0.2;
	return (SUCCESS);
}

int	_button_press(int keycode, t_glob *data)
{
	(void)keycode;
	data = _set_n_getglob(NULL);
	_free_n_exit(data, NULL);
	return (SUCCESS);
}