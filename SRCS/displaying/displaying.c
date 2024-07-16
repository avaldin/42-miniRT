/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:48:06 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/16 20:08:04 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "calcul.h"
#include "../../include/minilibx-linux/mlx.h"

static void	_set_vars_img(t_glob *data, int x, int y)
{
	static t_vars	vars;
	static t_img	img;

	data->window->vars = &vars;
	data->window->img = &img;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "miniRT");
	img.img = mlx_new_image(vars.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
		&img.line_length, &img.endian);
	_generate_image(data);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
}

void	_displaying(t_glob *data)
{
	_set_vars_img(data, X_SSIZE, Y_SSIZE);
	// mlx_loop_hook(data->window->vars->mlx, , data);
	mlx_loop(data->window->vars->mlx);
}