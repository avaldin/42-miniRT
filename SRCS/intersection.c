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
#include <stdio.h>
float	_inter_sphere(t_scene *scene, t_sphere *sphere, int i, int j)
{
	float	*axis_angle;
	float	result_a;
	float	result_b;

	axis_angle = _direct_axis(scene, i, j, scene->var);
	if (4 * _sq((scene->pov[0] - sphere->pos[0]) * axis_angle[0] + (scene->pov[1] - sphere->pos[1]) * axis_angle[1] + (scene->pov[2] - sphere->pos[2]) * axis_angle[2]) - 4 * (_sq(scene->pov[0] - sphere->pos[0]) + _sq(scene->pov[1] - sphere->pos[1]) + _sq(scene->pov[2] - sphere->pos[2])) + 4 * _sq(sphere->rayon) < 0)
		return (-1);
	result_a = 0 - (2 * ((scene->pov[0] - sphere->pos[0]) * axis_angle[0] + (scene->pov[1] - sphere->pos[1]) * axis_angle[1] + (scene->pov[2] - sphere->pos[2]) * axis_angle[2]) + sqrtf(4 * _sq((scene->pov[0] - sphere->pos[0]) * axis_angle[0] + (scene->pov[1] - sphere->pos[1]) * axis_angle[1] + (scene->pov[2] - sphere->pos[2]) * axis_angle[2]) - 4 * (_sq(scene->pov[0] - sphere->pos[0]) + _sq(scene->pov[1] - sphere->pos[1]) + _sq(scene->pov[2] - sphere->pos[2])) + 4 * _sq(sphere->rayon))) / 2;
	result_b = 0 - (2 * ((scene->pov[0] - sphere->pos[0]) * axis_angle[0] + (scene->pov[1] - sphere->pos[1]) * axis_angle[1] + (scene->pov[2] - sphere->pos[2]) * axis_angle[2]) - sqrtf(4 * _sq((scene->pov[0] - sphere->pos[0]) * axis_angle[0] + (scene->pov[1] - sphere->pos[1]) * axis_angle[1] + (scene->pov[2] - sphere->pos[2]) * axis_angle[2]) - 4 * (_sq(scene->pov[0] - sphere->pos[0]) + _sq(scene->pov[1] - sphere->pos[1]) + _sq(scene->pov[2] - sphere->pos[2])) + 4 * _sq(sphere->rayon))) / 2;
	//printf("a = %lf, b = %lf\n", result_a, result_b);
	if ((result_a >= 0 && result_a < result_b) || result_b < 0)
		return (result_a);
	return (result_b);
}

//void	_inter_cylinder(t_scene *scene, t_cylinder *cylinder, int i, int j)
//{
//
//}