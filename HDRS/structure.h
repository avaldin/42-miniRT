/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:21:44 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/22 16:24:29 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# define _NO_A "ARGUMENT NOT FOUND"
# define _2BIG_A "TOO MUCH ARGUMENTS"
# define _NOK_A "ARGUMENT NOT KNOWN"
# include <stddef.h>

typedef enum e_check
{
	SUCCESS,
	FAILURE
}			t_check;

/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */

typedef struct	s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef	struct	s_rgb
{
	int	red;
	int	green;
	int	blue;
}				t_rgb;

/* ************************************************************************** */
/*                                  SETTINGS                                  */
/* ************************************************************************** */

typedef struct s_amb
{
	float	ratio;
	t_rgb	*color;
}				t_amb;

typedef struct s_cam
{
	int		fov;
	t_coord	*pos;
	t_coord	*vect;
}				t_cam;

typedef struct s_spot
{
	float	ratio;
	t_coord	*pos;
	t_rgb	*color;

}				t_spot;

/* ************************************************************************** */
/*                                   OBJET                                    */
/* ************************************************************************** */

typedef struct	s_plane
{
	t_coord	*pos;
	t_coord	*vect;
	t_rgb	*color;
}				t_plane;

typedef struct	s_sphere
{
	float	diameter;
	t_coord	*pos;
	t_rgb	*color;
}				t_sphere;

typedef struct	s_cylinder
{
	float	height;
	float	diameter;
	t_coord	*pos;
	t_coord	*vect;
	t_rgb	*color;
}				t_cylinder;


//typedef struct	s_color
//{
//
//};

typedef struct	s_scene
{
	t_sphere		**sphere;
	t_plane			**plane;
	t_cylinder 		**cylinder;
	t_amb			*ambient;
	t_spot			*light;
	t_cam			*camera;
	t_coord			*dov_x;
	t_coord			*dov_y;
	t_coord			*dov_z;
	int				x_screen;
	int				y_screen;
	struct s_data	*data;
}				t_scene;

typedef struct	s_data
{
	t_scene	*scene;
}				t_data;

// t_scene	*_parsing(t_scene *scene);

#endif
