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

t_scene	*_parsing(t_scene *scene)
{
	scene = ft_calloc(1, sizeof(t_scene));
	scene->sphere = ft_calloc(2, sizeof(t_sphere *));
	scene->sphere[0] = ft_calloc(1, sizeof(t_sphere ));
	scene->sphere[0]->pos[0] = 10;
	scene->sphere[0]->pos[1] = 0;
	scene->sphere[0]->pos[2] = 0;
	scene->sphere[0]->rayon = 2;
	scene->sphere[0]->color[1] = 255;
	scene->dov_z[0] = 1;
	scene->fov = 70;
	scene->x_screen = 1920;
	scene->y_screen = 1080;
	return (scene);

}
