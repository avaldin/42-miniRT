/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:54:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/08/20 04:04:54 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYING_H
# define DISPLAYING_H
# include "structure.h"
# define _MLX_ERR "MLX INIT ERROR"

void	_mlx_pixel_put(t_img *data, int x, int y, int color);
void	_displaying(t_glob *data);
int		_new_frame(t_glob *data);

/* *********************HOOKING********************************************* */
/* ---KEYBOARD---                                                            */
int		_key_release(int keycode, t_glob *data);
int		_key_press(int keycode, t_glob *data);
/* ---MOUSE---                                                               */
int		_mouse_mv(int loc_x, int loc_y, t_glob *data);
int		_focus_in(void);
int		_focus_out(void);
int		_cross_notify(void);

t_check	_init_mvt_struct(t_kntc *kinetic, t_cam *cam);
void	_change_cam_pos_y(t_cam *cam, float mv);
void	_change_cam_pos_x(t_cam *cam, t_coord *vect_dir, float mv);
void	_change_cam_pos_z(t_cam *cam, t_coord *vect_dir, float mv);

#endif