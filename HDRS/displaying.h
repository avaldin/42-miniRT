/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:54:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 02:07:18 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include "structure.h"
# define _MLX_ERR "MLX INIT ERROR"

void	_mlx_pixel_put(t_img *data, int x, int y, int color);
void	_displaying(t_glob *data);

/* *********************HOOKING********************************************* */
int	_key_press(void *data);
int	_button_press(void *data);
int	_key_release(void *data);

#endif