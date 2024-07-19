/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:54:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/19 03:28:43 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include "structure.h"
# define _MLX_ERR "MLX INIT ERROR"

void	_mlx_pixel_put(t_img *data, int x, int y, int color);
void	_displaying(t_glob *data);

/* *********************HOOKING********************************************* */
int	_key_press(int keycode, t_glob *data);
int	_button_press(int keycode);
int	_key_release(int keycode, t_glob *data);
int	_notify_out(void);
int	_notify_in(void);
int	_mouse_mv(int keycode, int keycode2, t_glob *data);

#endif