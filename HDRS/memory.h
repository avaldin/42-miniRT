/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:39:55 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 01:39:09 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# include "structure.h"

void	_freetab(char **tab);

void	_free_plane(t_plane **pla);
void	_free_sphere(t_sphere **sph);
void	_free_cylinder(t_cylinder **cyl);

void	_free_scene(t_scene *scene, char *err);
void	_free_window(t_wdw *window);

void	_free_n_exit(t_glob *data, char *err);

#endif