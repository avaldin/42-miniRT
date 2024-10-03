/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_disp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:50:44 by thibaud           #+#    #+#             */
/*   Updated: 2024/10/02 18:25:41 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "../include/minilibx-linux/mlx.h"
#include <stdlib.h>

void	_free_window(t_wdw *window)
{
	if (!window->vars->mlx)
		return ;
	if (window->img->img)
		mlx_destroy_image(window->vars->mlx, window->img->img);
	if (window->vars->win)
		mlx_destroy_window(window->vars->mlx, window->vars->win);
	mlx_destroy_display(window->vars->mlx);
	free (window->vars->mlx);
}
