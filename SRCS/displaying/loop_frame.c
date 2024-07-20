/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/20 03:26:08 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"
#include "calcul.h"
#include "displaying.h"
#include "../include/minilibx-linux/mlx.h"
#include "stdio.h"

int	_new_frame(t_glob *data)
{
	static int	until_new = 0;
	t_cam	*cam;

	if (data->window->box == IN && until_new >= SET_FRM)
	{
		cam = data->scene->camera;
		if (data->kinetic->cam_moov->mv_x > 0)
			_change_cam_pos(cam, data->kinetic->cam_moov->dir_x, 0.2);
		if (data->kinetic->cam_moov->mv_x < 0)
			_change_cam_pos(cam, data->kinetic->cam_moov->dir_bx, 0.2);
		if (data->kinetic->cam_moov->mv_y > 0)
			_change_cam_pos(cam, data->kinetic->cam_moov->dir_y, 0.2);
		if (data->kinetic->cam_moov->mv_y < 0)
			_change_cam_pos(cam, data->kinetic->cam_moov->dir_by, 0.2);
		mlx_destroy_image(data->window->vars->mlx, data->window->img->img);
		data->window->img->img = mlx_new_image(data->window->vars->mlx, X_SSIZE, Y_SSIZE);
		data->window->img->addr = mlx_get_data_addr(data->window->img->img, &data->window->img->bits_per_pixel, 
			&data->window->img->line_length, &data->window->img->endian);
		_generate_image(data);
		mlx_put_image_to_window(data->window->vars->mlx, data->window->vars->win, data->window->img->img, 0, 0);
		until_new = 0;
		printf("cam dir x %f\n", cam->vect->x);
		printf("cam dir y %f\n", cam->vect->y);
		printf("cam dir z %f\n", cam->vect->z);
	}
	++until_new;
	return (SUCCESS);
}
