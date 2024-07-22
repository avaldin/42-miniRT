/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/22 22:51:58 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"
#include "calcul.h"
#include "displaying.h"
#include "../include/minilibx-linux/mlx.h"
#include "stdio.h"
#include "math.h"

void	_change_cam_direction_x(t_glob *data)
{
	float	angle;
	t_coord	x;
	t_coord	y;
	
	angle = acos(data->kinetic->cam_rotate->mv_x / (sqrt(powf(data->kinetic->cam_rotate->mv_x, 2.) + powf(data->kinetic->cam_rotate->mv_y, 2.))));
	x.x = 1;
	x.y = 0;
	x.z = 0;
	y.x = 0;
	y.y = 1;
	y.z = 0;
	_rotate_vec_3d(data->scene->camera->vect, &x, angle);
}

void	_change_cam_direction_y(t_glob *data)
{
	float	angle;
	t_coord	x;
	t_coord	y;
	
	angle = acos(data->kinetic->cam_rotate->mv_x / (sqrt(powf(data->kinetic->cam_rotate->mv_x, 2.) + powf(data->kinetic->cam_rotate->mv_y, 2.))));
	x.x = 1;
	x.y = 0;
	x.z = 0;
	y.x = 0;
	y.y = 1;
	y.z = 0;
	_rotate_vec_3d(data->scene->camera->vect, &x, angle);
	_rotate_vec_3d(data->scene->camera->vect, &y, 90 - angle);
}

int	_new_frame(t_glob *data)
{
	static int	until_new = 0;
	t_cam	*cam;

	if (data->window->box == IN && until_new >= SET_FRM)
	{
		cam = data->scene->camera;
		if (data->kinetic->cam_moov->mv_x > 0)
			_change_cam_pos_x(cam, cam->vect, 1.);
		else if (data->kinetic->cam_moov->mv_x < 0)
			_change_cam_pos_x(cam, cam->vect, -1.);
		if (data->kinetic->cam_moov->mv_z > 0)
			_change_cam_pos_z(cam, cam->vect, 1.);
		else if (data->kinetic->cam_moov->mv_z < 0)
			_change_cam_pos_z(cam, cam->vect, -1.);
		if (data->kinetic->cam_moov->mv_y > 0)
			_change_cam_pos_y(cam, 1.);
		else if (data->kinetic->cam_moov->mv_y < 0)
			_change_cam_pos_y(cam, -1.);
		if (data->kinetic->cam_rotate->mv_x != 0 || data->kinetic->cam_rotate->mv_y != 0)
			_change_cam_direction_x(data);
		mlx_destroy_image(data->window->vars->mlx, data->window->img->img);
		data->window->img->img = mlx_new_image(data->window->vars->mlx, X_SSIZE, Y_SSIZE);
		data->window->img->addr = mlx_get_data_addr(data->window->img->img, &data->window->img->bits_per_pixel, 
			&data->window->img->line_length, &data->window->img->endian);
		_generate_image(data);
		mlx_put_image_to_window(data->window->vars->mlx, data->window->vars->win, data->window->img->img, 0, 0);
		// mlx_mouse_hide(data->window->vars->mlx, data->window->vars->win);
		data->kinetic->cam_rotate->mv_x = 0;
		data->kinetic->cam_rotate->mv_y = 0;
		// mlx_mouse_move(data->window->vars->mlx, data->window->vars->win, X_SSIZE / 2, Y_SSIZE / 2);
		until_new = 0;
	}
	++until_new;
	return (SUCCESS);
}
