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

float	*_matrix_var(t_scene *scene);
void	_dov(t_scene *scene, float *var);
void	_generate_image(t_glob *data);
float	_eq_sec_deg(float a, float b, float c);
//float	_inter_plane(t_scene *scene, t_plane *plane, int i, int j);
float	_inter_sphere(t_scene *scene, t_sphere *sphere, int i, int j);
//float	_inter_cylinder(t_scene *scene, t_cylinder *cylinder , int i, int j);
t_coord	*_direct_axis(t_scene *scene, int i, int j, float *var);
float	_sq(float x);
float	_find_intensity(t_scene *scene, float length);
int		*_rgb_render(t_scene *scene, float intensity);

#endif