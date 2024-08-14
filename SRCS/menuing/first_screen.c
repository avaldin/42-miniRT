/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 00:57:11 by thibaud           #+#    #+#             */
/*   Updated: 2024/08/14 01:55:32 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "../include/minilibx-linux/mlx.h"
#include <stdio.h>

static inline void	_display_screen(t_glob *data)
{
	int		width;
	int 	height;
	void	*img;

	img = mlx_xpm_file_to_image(data->window->vars->mlx, "./design/bannerFstScreen.xpm", &width, &height);
	mlx_put_image_to_window(data->window->vars->mlx,
			data->window->vars->win, img, 0, 0);
}

t_check	_first_screen(t_glob *data)
{
	_display_screen(data);
	return (SUCCESS);
}

