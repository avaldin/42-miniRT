/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:54:14 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/19 18:33:49 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"
#include "calcul.h"
#include <math.h>
#include <stdio.h>
#include "../../include/minilibx-linux/mlx.h"

void	_change_cam_pos(t_cam *cam, t_coord *matrix, float mv)
{
	float	nvec;

	nvec = (float)sqrt(pow(matrix->x, 2.) + pow(matrix->y, 2.) + pow(matrix->z, 2.));
	cam->pos->x = cam->pos->x + (mv * (matrix->x) / nvec);
	cam->pos->y = cam->pos->y + (mv * (matrix->y) / nvec);
	cam->pos->z = cam->pos->z + (mv * (matrix->z) / nvec);
}

int	_moove_cam(t_glob *data)
{
	t_cam	*cam;

	cam = data->scene->camera;
	if (data->kinetic->mv_x > 0)
		_change_cam_pos(cam, data->kinetic->dir_x, 0.2);
	if (data->kinetic->mv_x < 0)
		_change_cam_pos(cam, data->kinetic->dir_bx, 0.2);
	if (data->kinetic->mv_y > 0)
		_change_cam_pos(cam, data->kinetic->dir_y, 0.2);
	if (data->kinetic->mv_y < 0)
		_change_cam_pos(cam, data->kinetic->dir_by, 0.2);
	if ((data->kinetic->mv_x || data->kinetic->mv_y) && data->window->box == IN)
	{
		mlx_destroy_image(data->window->vars->mlx, data->window->img->img);
		data->window->img->img = mlx_new_image(data->window->vars->mlx, X_SSIZE, Y_SSIZE);
		data->window->img->addr = mlx_get_data_addr(data->window->img->img, &data->window->img->bits_per_pixel, 
			&data->window->img->line_length, &data->window->img->endian);
		_generate_image(data);
		mlx_put_image_to_window(data->window->vars->mlx, data->window->vars->win, data->window->img->img, 0, 0);
		mlx_mouse_hide(data->window->vars->mlx, data->window->vars->win);
		mlx_mouse_move(data->window->vars->mlx, data->window->vars->win, X_SSIZE / 2, Y_SSIZE / 2);
	}
	return (1);
}

t_check	_init_mvt_struct(t_mvt *kinetic, t_cam *cam)
{
	kinetic->mv_x = 0;
	kinetic->mv_y = 0;
	kinetic->dir_x = _alloc_coord(cam->vect->x, cam->vect->y, cam->vect->z);
	kinetic->dir_y = _alloc_coord(-cam->vect->x, cam->vect->y, 0.);
	kinetic->dir_bx = _alloc_coord(-cam->vect->x, -cam->vect->y, -cam->vect->z);
	kinetic->dir_by = _alloc_coord(cam->vect->x, cam->vect->y, 0.);
	if (kinetic->dir_x && kinetic->dir_y && kinetic->dir_bx && kinetic->dir_by)
		return (SUCCESS);
	_free_mvt(kinetic);
	return (FAILURE);
}