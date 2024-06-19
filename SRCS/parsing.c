/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:42:41 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 15:48:33 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../include/libft/libft.h"

void	_parsing(t_data *data)
{
	t_scene *scene = data->scene;
	scene = ft_calloc(1, sizeof(t_scene *));
	scene->sphere = ft_calloc(1, sizeof(t_sphere *));
	t_sphere *sphere = data->scene->sphere[0];
	sphere->pos[0] = 10;
	sphere->pos[1] = 0;
	sphere->pos[2] = 0;
	sphere->rayon = 14.54;
	sphere->color[1] = 255;
	scene->dov[0] = 1;
	scene->fov = 70;
	scene->x_screen = 1920;
	scene->y_screen = 1080;

}
