/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:42:41 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 13:43:57 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../include/libft/libft.h"

void	_parsing(t_data *data)
{
	t_scene *scene = data->scene;
	t_sphere *sphere = data->scene->sphere;
	scene = ft_calloc(1, sizeof(t_scene));
	sphere = ft_calloc(1, sizeof(t_sphere));
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
