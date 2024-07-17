/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 03:00:44 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"

int	_key_release(int keycode, t_glob *data)
{
	t_cam	*cam;

	cam = data->scene->camera;
	if (keycode == 'w')
		cam->mvt->x = 0;
	if (keycode == 'a')
		cam->mvt->y = 0;
	if (keycode == 's')
		g->info->mv_y = 0;
	if (keycode == 'd')
		g->info->mv_x = 0;
	return (SUCCESS);
}

int	_key_press(int keycode, t_glob *data)
{
	return (SUCCESS);
}

int	_button_press(int keycode, t_glob *data)
{
	(void)keycode;
	_free_n_exit(data, NULL);
	return (SUCCESS);
}