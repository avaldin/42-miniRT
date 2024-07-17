/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:48:06 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/17 02:08:48 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "displaying.h"
#include "memory.h"
#include "calcul.h"
#include "../../include/minilibx-linux/mlx.h"

static t_check	_set_vars_img(t_glob *data, int x, int y)
{
	static t_vars	vars;
	static t_img	img;

	data->window->vars = &vars;
	data->window->img = &img;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (FAILURE);
	vars.win = mlx_new_window(vars.mlx, x, y, "miniRT");
	if (!vars.win)
		return (FAILURE);
	img.img = mlx_new_image(vars.mlx, x, y);
	if (!img.img)
		return (FAILURE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
		&img.line_length, &img.endian);
	if (!img.addr)
		return (FAILURE);
	_generate_image(data);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	return (SUCCESS);
}

void	_displaying(t_glob *data)
{
	if (_set_vars_img(data, X_SSIZE, Y_SSIZE) == FAILURE)
		return (_free_n_exit(data, _MLX_ERR));
	mlx_hook(data->window->vars->win, 3, 1L << 1, _key_release, data);
	mlx_hook(data->window->vars->win, 2, 1L << 0, _key_press, data);
	mlx_hook(data->window->vars->win, 17, 1L << 2, _button_press, data);
	// mlx_loop_hook(data->window->vars->mlx, , data);
	mlx_loop(data->window->vars->mlx);
}