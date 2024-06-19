/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:50:15 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 12:55:25 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stddef.h>

typedef struct	s_plane
{
	float	pos[3];
	float	vect[3];
	int		color[3];
	struct s_plane	*next;
}				t_plane;

typedef struct	s_sphere
{
	float	pos[3];
	float	rayon;
	int		color[3];
	struct s_sphere	*next;
}				t_sphere;

typedef struct	s_cylinder
{
	float	pos[3];
	float	vect[3];
	float	diameter;
	float	height;
	int		color[3];
	struct s_cylinder	*next;
}				t_cylinder;

typedef struct	s_scene
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder 	*cylinder;
	float		pov[3];
	float		dov[3];
	float		fov;
	int			x_screen;
	int			y_screen;
}				t_scene;

typedef struct	s_data
{
	t_scene	*scene;
}				t_data;

typedef enum
{
	FAIL,
	SUCCESS
}				e_test;

int	_parsing(t_data *data);


#endif
