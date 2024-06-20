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

void	_generate_image(t_scene *scene);
float	_eq_sec_deg(float a, float b, float c);
//float	_inter_plane(t_scene *scene, t_plane *plane, int i, int j);
float	_inter_sphere(t_scene *scene, t_sphere *sphere, int i, int j);
//float	_inter_cylinder(t_scene *scene, t_cylinder *cylinder , int i, int j);
float	_direct_axis(t_scene *scene, int i, int j, int axis);

#endif