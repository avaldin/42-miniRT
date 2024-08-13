/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 04:49:00 by thibaud           #+#    #+#             */
/*   Updated: 2024/08/13 05:26:18 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "displaying.h"
#include "../include/minilibx-linux/mlx.h"

t_check	_first_screen(t_glob *data)
{
	mlx_xpm_file_to_image(data->window->vars->mlx, "../../design/bannerFstScreen", 0, 0);
	
}

t_check	_menu(t_glob *data)
{
	t_check	res;
	int	x;
	int y;
	
	y = -1;
	while (++y < Y_SSIZE)
	{
		x = -1;
		while (++x < X_SSIZE)
			_mlx_pixel_put(data->window->img, x, y, 0);
	}
	if (data->menu->screen == FIRST_SCREEN)
		res = _first_screen(data);
	else if (data->menu->screen == OBJET_SCREEN)
		res = _objet_screen();
	else if (data->menu->screen == CHANGE_SCREEN)
		res = _change_screen();
	else
		res = FAILURE;
	return (res);
}