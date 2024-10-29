/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/10/28 15:24:10 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "libft.h"
#include "memory.h"
#include "parsing.h"
#include "calcul.h"
#include "structure.h"
#include "displaying.h"
#include "../include/minilibx-linux/mlx.h"

static inline void	_change_cam_direction_x(t_cam *camera, t_rtn *cam_rotate)
{
	float	angle;
	t_coord	x;

	angle = cam_rotate->mv_x * 0.1f * (_PI / 180);
	if (cam_rotate->loc_x < X_SSIZE / 2)
		angle = 6.283185 - angle;
	if (angle == 0 || angle == 6.283185f)
		return ;
	x.x = 0;
	x.y = 1;
	x.z = 0;
	_rotate_vec_3d(camera->vect, &x, angle);
}

static inline void	_change_cam_direction_y(t_cam *camera, t_rtn *cam_rotate)
{
	float			angle;
	t_coord			y;
	t_coord const	axis_y = {0.0, 1.0, 0.0};

	angle = cam_rotate->mv_y * 0.1 * (_PI / 180);
	if (cam_rotate->loc_y > Y_SSIZE / 2)
		angle = 6.283185 - angle;
	if (angle == 0 || angle == 6.283185f)
		return ;
	y.x = camera->vect->x;
	y.y = camera->vect->y;
	y.z = camera->vect->z;
	_rotate_vec_3d(&y, &axis_y, 1.5708f);
	_rotate_vec_3d(camera->vect, &y, angle);
}

static inline void	_update_cam(t_cam *cam, t_kntc *kinetic)
{
	if (kinetic->cam_moov->mv_x > 0)
		_change_cam_pos_x(cam, cam->vect, 1.);
	else if (kinetic->cam_moov->mv_x < 0)
		_change_cam_pos_x(cam, cam->vect, -1.);
	if (kinetic->cam_moov->mv_z > 0)
		_change_cam_pos_z(cam, cam->vect, 1.);
	else if (kinetic->cam_moov->mv_z < 0)
		_change_cam_pos_z(cam, cam->vect, -1.);
	if (kinetic->cam_moov->mv_y > 0)
		_change_cam_pos_y(cam, 1.);
	else if (kinetic->cam_moov->mv_y < 0)
		_change_cam_pos_y(cam, -1.);
	if (kinetic->cam_rotate->loc_x != X_SSIZE / 2)
		_change_cam_direction_x(cam, kinetic->cam_rotate);
	if (kinetic->cam_rotate->loc_y != Y_SSIZE / 2)
		_change_cam_direction_y(cam, kinetic->cam_rotate);
	kinetic->cam_rotate->mv_x = 0;
	kinetic->cam_rotate->mv_y = 0;
}

inline static void	_reset_window(t_glob *data)
{
	int	i;
	int	j;

	mlx_clear_window(data->window->vars->mlx, data->window->vars->win);
	i = 0;
	while (i < X_SSIZE)
	{
		j = 0;
		while (j < Y_SSIZE)
		{
			_mlx_pixel_put(data->window->img, i, j, 0);
			j++;
		}
		i++;
	}
}

int	_new_frame(t_glob *data)
{
	static int	until_new = 0;

	if (data->window->box == IN && until_new >= SET_FRM)
	{
		if (data->window->interf == SCENE)
		{
			_reset_window(data);
			_update_cam(data->scene->camera, data->kinetic);
			_generate_image(data);
			if (data->scene->state == 1)
			{
				mlx_mouse_hide(data->window->vars->mlx,
					data->window->vars->win);
				mlx_mouse_move(data->window->vars->mlx, data->window->vars->win,
					X_SSIZE / 2, Y_SSIZE / 2);
			}
			mlx_put_image_to_window(data->window->vars->mlx,
				data->window->vars->win, data->window->img->img, 0, 0);
		}
		else if (_menu(data) == ERROR)
			_free_n_exit(data, "error : menu issue\n");
		until_new = 0;
	}
	++until_new;
	return (SUCCESS);
}
