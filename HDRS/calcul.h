/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:28 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/16 20:07:36 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H

# include "structure.h"

# define LENGTH_MITIGATION 1000

float	*_matrix_var(t_scene *scene);
void	_dov(t_scene *scene, float *var);
void	_generate_image(t_glob *data);
float	_eq_sec_deg(float a, float b, float c);
float	_inter_plane(t_scene *scene, t_plane *plane, t_coord *axis);
float	_inter_sphere(t_scene *scene, t_sphere *sphere, t_coord *axis);
float	_inter_cylinder(t_scene *scene, t_cylinder *cylinder , t_coord *axis);
t_coord	*_direct_axis(t_scene *scene, int i, int j, float *var);
float	_sq(float x);
float	_intensity_of_sphere(t_scene *scene, float length, void *object);
float	_intensity_of_plane(t_scene *scene, float length, void *object);
int		*_rgb_render(t_scene *scene, float intensity, float length);
t_coord	_intersection_on_line(t_coord *pos, t_coord *axis, float length);
float	_projection(t_coord	point, t_coord *pos, t_coord *vect);

#endif