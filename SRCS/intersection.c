/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:03:00 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 18:55:26 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/calcul.h"
#include <math.h>

//float	_inter_plane(t_scene *scene, t_plane *plane, int i, int j)
//{
//
//}

float	_inter_sphere(t_scene *scene, t_sphere *sphere, int i, int j)
{
	float		a;
	float		b;
	float		c;
	float		*axis_angle;

	axis_angle = _direct_axis(scene, i, j, scene->var);
	a = 1;
	b = 2 * ((scene->pov[0] - sphere->pos[0]) * axis_angle[0]
			+ (scene->pov[1] - sphere->pos[1]) * axis_angle[1]
			+ (scene->pov[2] - sphere->pos[2]) * axis_angle[2]);
	c = powf(scene->pov[0] - sphere->pos[0], 2)
		+ powf(scene->pov[1] - sphere->pos[1], 2)
		+ powf(scene->pov[2] - sphere->pos[2], 2) - powf(sphere->rayon, 2);
	return (_eq_sec_deg(a, b, c));
}

//void	_inter_cylinder(t_scene *scene, t_cylinder *cylinder, int i, int j)
//{
//
//}