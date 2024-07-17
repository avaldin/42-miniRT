/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:39:55 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 17:34:51 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# include "structure.h"

void	_freetab(char **tab);

t_coord	*_alloc_coord(float x, float y, float z);
t_rgb	*_alloc_rgb(int red, int green, int blue);

void	_free_mvt(t_mvt *kinetic);

void	_free_plane(t_plane **pla);
void	_free_sphere(t_sphere **sph);
void	_free_cylinder(t_cylinder **cyl);

void	_free_scene(t_scene *scene, char *err);
void	_free_window(t_wdw *window);

void	_free_n_exit(t_glob *data, char *err);

#endif