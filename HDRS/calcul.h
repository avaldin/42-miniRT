/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:28 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/21 02:08:58 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H
# include "structure.h"
# define LENGTH_MITIGATION 1000
# define _PI 3.14156

float	*_matrix_var(t_scene *scene);
void	_dov(t_scene *scene, float *var);
t_coord	***_generate_axis(t_cam *camera, t_coord ***axis);
void	_generate_image(t_glob *data);
void	_rebase_objects(t_scene *scene);
float	_inter_plane(t_coord *pos, t_plane *plane, t_coord *axis);
float	_inter_sphere(t_coord *pos, t_sphere *sphere, t_coord *axis);
float	_inter_cylinder(t_coord *pos, t_cylinder *cylinder , t_coord *axis);
float	_find_length(float length, t_scene *scene,t_coord *pos, t_coord *axis);

float	_eq_sec_deg(float a, float b, float c);
t_coord	*_direct_axis(t_cam *camera, int i, int j);
float	_sq(float x);

float	_intensity_of_sphere(t_scene *scene, float length, void *object, t_coord *axis);
float	_intensity_of_plane(t_scene *scene, float length, void *object, t_coord *axis);
float	_intensity_of_cylinder(t_scene *scene, float length, void *object, t_coord *axis);
int		*_rgb_render(t_scene *scene, float intensity, float length);

void	_rotate_vec_3d(t_coord *vec, t_coord *axis, float angle);
void	_rotate_vec_2d(float *x, float *y, float angle);
t_coord	_intersection_on_line(t_coord *pos, t_coord *axis, float length);
float	_projection(t_coord	point, t_coord *pos, t_coord *vect);
void	_normalized(t_coord *vect);

#endif