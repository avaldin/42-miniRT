/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:45:42 by thibaud           #+#    #+#             */
/*   Updated: 2024/06/30 16:10:46 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../HDRS/pixel.h"

void	_mlx_pixel_put(t_data *data, int x, int y, int color) 
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	_set_vars_img(t_struct *g, int x, int y)
{
	g->vars->mlx = mlx_init();
	g->vars->win = mlx_new_window(g->vars->mlx, x, y, "test miniRT");
	g->img->img = mlx_new_image(g->vars->mlx, x, y);
	g->img->addr = mlx_get_data_addr(g->img->img, &g->img->bits_per_pixel, &g->img->line_length,
			&g->img->endian);
}

int	_looper(t_struct *g)
{
	int	x = 0; // coordonnée en abs du pxl dans l image
	int	y = 0; // coordonnée en ord du pxl dans l image
	int color = 0; // color du pxl
	
	_mlx_pixel_put(g->img, x, y, color);
	mlx_put_image_to_window(g->vars->mlx, g->vars->win, g->img->img, 0, 0);
	return (0);
}

void	_window(t_struct *g)
{
	mlx_put_image_to_window(g->vars->mlx, g->vars->win, g->img->img, 0, 0);
	mlx_loop_hook(g->vars->mlx, _looper, g);
	mlx_loop(g->vars->mlx);
}
