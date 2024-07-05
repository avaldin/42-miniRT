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

#include "../HDRS/calcul.h"
#include "../include/libft/libft.h"
#include <math.h>

t_scene	*_parsing(t_scene *scene)
{
	float	x = 1.0f;
	float	y = 0.0f;
	float	z = 0.0f;

	scene = ft_calloc(1, sizeof(t_scene));
	scene->sphere = ft_calloc(2, sizeof(t_sphere *));
	scene->sphere[0] = ft_calloc(1, sizeof(t_sphere ));
	scene->sphere[0]->pos = ft_calloc(1, sizeof(t_coord));
	scene->sphere[0]->pos->x = 10.0f;
	scene->sphere[0]->pos->y = 0.0f;
	scene->sphere[0]->pos->z = 0.0f;
	scene->sphere[0]->radius = 2.0f;
	scene->camera = ft_calloc(1, sizeof(t_cam));
	scene->camera->pos = ft_calloc(1, sizeof(t_coord));
	scene->camera->pos->x = -10.0f;
	scene->camera->pos->y = 5.0f;
	scene->camera->pos->z = 0.0f;
	scene->camera->vect = ft_calloc(1, sizeof(t_coord));
	scene->camera->vect->x = x / (sqrtf(_sq(x) + _sq(y) + _sq(z)));
	scene->camera->vect->y = y / (sqrtf(_sq(x) + _sq(y) + _sq(z)));
	scene->camera->vect->z = z / (sqrtf(_sq(x) + _sq(y) + _sq(z)));
	scene->camera->fov = 70;
	scene->x_screen = 1920;
	scene->y_screen = 1080;
	return (scene);


}

test