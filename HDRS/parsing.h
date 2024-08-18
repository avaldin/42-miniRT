/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:02:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/08/18 11:41:01 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define _NO_A "ARGUMENT NOT FOUND"
# define _2BIG_A "TOO MUCH ARGUMENTS"
# define _NOK_A "ARGUMENT NOT KNOWN"
# define _NOK_ID "IDENTIFIER NOT KNOWN"
# include "structure.h"
# define BUFFER_SIZE 100

/* *********************UTILS*********************************************** */
void	_strerror(char *str);
char	*_is_space(char *line);
t_check	check_line(char *line);
char	*_until_char(char *line, char c);
char	*_is_inrange(char *line, char r_bot, char r_top);

t_check	_check_rgb(t_rgb *colors);
t_rgb	*_set_rgb(char *line);

t_check	_check_coord(t_coord *coord, float range_min, float range_max);
t_coord	*_set_coord(char *line);

/* *********************OBJS************************************************ */
t_check	_check_sphere(t_sphere **sphere, char *line);
t_check	_init_sphere(t_sphere **sphere, char *line);
t_check	_sphere_table(t_scene *scene, char *line);
t_check	_check_plane(t_plane **plane, char *line);
t_check	_init_plane(t_plane **plane, char *line);
t_check	_plane_table(t_scene *scene, char *line);
t_check	_check_cylinder(t_cylinder **cylinder, char *line);
t_check	_init_cylinder(t_cylinder **cylinder, char *line);
t_check	_cylinder_table(t_scene *scene, char *line);

/* *********************ENVS************************************************ */
t_check	_check_ambient(t_amb **ambient, char *line);
t_check	_init_ambient(t_amb **ambient, char *line);
t_check	_check_camera(t_cam **camera, char *line);
t_check	_init_camera(t_cam **camera, char *line);
t_check	_check_light(t_spot **light, char *line);
t_check	_init_light(t_spot **light, char *line);
void	_free_scene(t_scene *scene, char *err);

/* *********************ENVS************************************************ */
t_check	_menu(t_glob *data);
t_mstate	_select_cylinder(t_cylinder **cylinder);


char	*get_next_line(int fd);
t_scene	*_extract_data(char	*path_file);
t_check	_check_args(int	argc, char **argv);

#endif