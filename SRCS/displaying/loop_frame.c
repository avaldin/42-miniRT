/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/23 06:02:32 by thibaud          ###   ########.fr       */
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
	
	angle = acos(data->kinetic->cam_rotate->mv_x / (sqrt(powf(data->kinetic->cam_rotate->mv_x, 2.) + powf(data->kinetic->cam_rotate->mv_y, 2.))));
	if ((data->kinetic->cam_rotate->mv_x < X_SSIZE / 2 && data->kinetic->cam_rotate->mv_y > Y_SSIZE)
		|| (data->kinetic->cam_rotate->mv_x > X_SSIZE / 2 && data->kinetic->cam_rotate->mv_y < Y_SSIZE))
		angle = 6.283185 - angle;
	if (angle == 0 || angle == 6.28f)
		return ;
	x.x = 0;
	x.y = 1;
	x.z = 0;
	// printf("beforeX x:%f, y:%f, z:%f\n", data->scene->camera->vect->x, data->scene->camera->vect->y, data->scene->camera->vect->z);
	_rotate_vec_3d(data->scene->camera->vect, &x, angle);
	// printf("afterX x:%f, y:%f, z:%f\n", data->scene->camera->vect->x, data->scene->camera->vect->y, data->scene->camera->vect->z);
}

void	_change_cam_direction_y(t_glob *data)
{
	float	angle;
	t_coord	y;
	
	angle = acos(data->kinetic->cam_rotate->mv_x / (sqrt(powf(data->kinetic->cam_rotate->mv_x, 2.) + powf(data->kinetic->cam_rotate->mv_y, 2.))));
	if ((data->kinetic->cam_rotate->mv_x < X_SSIZE / 2 && data->kinetic->cam_rotate->mv_y < Y_SSIZE)
		|| (data->kinetic->cam_rotate->mv_x > X_SSIZE / 2 && data->kinetic->cam_rotate->mv_y > Y_SSIZE))
		angle = 6.283185 - angle;
	if (angle == 0 || angle == 6.28f)
		return ;
	y.x = 1;
	y.y = 0;
	y.z = 0;
	_rotate_vec_3d(data->scene->camera->vect, &y, angle);
}

int	_new_frame(t_glob *data)
{
	static int	until_new = 0;
	static int	frame = 0;
	t_cam		*cam;

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
		// printf("---------------\n");
		// printf("before x:%f, y:%f, z:%f\n", cam->vect->x, cam->vect->y, cam->vect->z);
		if (data->kinetic->cam_rotate->mv_x != 0)
			_change_cam_direction_x(data);
		if (data->kinetic->cam_rotate->mv_y != 0 && data->scene->camera->vect->y == 1.f)
			_change_cam_direction_y(data);
		// printf("after x:%f, y:%f, z:%f\n", cam->vect->x, cam->vect->y, cam->vect->z);
		// printf("---------------\n");
		mlx_destroy_image(data->window->vars->mlx, data->window->img->img);
		data->window->img->img = mlx_new_image(data->window->vars->mlx, X_SSIZE, Y_SSIZE);
		data->window->img->addr = mlx_get_data_addr(data->window->img->img, &data->window->img->bits_per_pixel, 
			&data->window->img->line_length, &data->window->img->endian);
		_generate_image(data);
		mlx_put_image_to_window(data->window->vars->mlx, data->window->vars->win, data->window->img->img, 0, 0);
		// mlx_mouse_hide(data->window->vars->mlx, data->window->vars->win);
		data->kinetic->cam_rotate->mv_x = 0;
		data->kinetic->cam_rotate->mv_y = 0;
		mlx_mouse_move(data->window->vars->mlx, data->window->vars->win, X_SSIZE / 2, Y_SSIZE / 2);
		until_new = 0;
		++frame;
	}
	++until_new;
	return (SUCCESS);
}
