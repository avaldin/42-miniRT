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
	scene->sphere[0]->pos[0] = 0.0f;
	scene->sphere[0]->pos[1] = 0.0f;
	scene->sphere[0]->pos[2] = 10.0f;
	scene->sphere[0]->rayon = 4.0f;
	scene->sphere[0]->color[1] = 255;
	scene->pov[0] = 0.0f;
	scene->pov[1] = 0.0f;
	scene->pov[2] = 0.0f;
	scene->dov_z[0] = 0.0f;
	scene->dov_z[1] = 0.0f;
	scene->dov_z[2] = 1.0f;
	scene->fov = 70;
	scene->x_screen = 1920;
	scene->y_screen = 1080;
	return (scene);

}
