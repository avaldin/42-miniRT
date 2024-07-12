/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:55:28 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 18:24:16 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H

# include "structure.h"

float	*_matrix_var(t_scene *scene);
void	_dov(t_scene *scene, float *var);
void	_generate_image(t_scene *scene);
float	_eq_sec_deg(float a, float b, float c);
//float	_inter_plane(t_scene *scene, t_plane *plane, t_coord *axis);
float	_inter_sphere(t_scene *scene, t_sphere *sphere, t_coord *axis);
//float	_inter_cylinder(t_scene *scene, t_cylinder *cylinder , t_coord *axis);
t_coord	*_direct_axis(t_scene *scene, int i, int j, float *var);
float	_sq(float x);
float	_find_intensity(t_scene *scene, float length);
int		*_rgb_render(t_scene *scene, float intensity);

#endif