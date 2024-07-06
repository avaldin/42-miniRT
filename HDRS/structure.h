/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:21:44 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/07 01:29:23 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include <stddef.h>
# include <errno.h>

typedef enum e_check
{
	SUCCESS,
	FAILURE
}			t_check;

typedef enum e_type
{
	OBJ_PLA,
	OBJ_SPH,
	OBJ_CYL,
	ENV_AMB,
	ENV_CAM,
	ENV_SPT
}			t_type;

/* ************************************************************************** */
/*                                   TOOLS                                    */
/* ************************************************************************** */

typedef struct s_coord
{
	float	x;
	float	y;
	float	z; 
}				t_coord;

typedef	struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}				t_rgb;

typedef struct s_rescam
{
	float	cos_x;
	float	sin_x;
	float	cos_y;
	float	sin_y;
}				t_rescam;

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

typedef struct s_plane
{
	t_coord	*pos;
	t_coord	*vect;
	t_rgb	*color;
}				t_plane;

typedef struct s_sphere
{
	float	radius;
	t_coord	*pos;
	t_rgb	*color;
}				t_sphere;

typedef struct s_cylinder
{
	float	height;
	float	radius;
	t_coord	*pos;
	t_coord	*vect;
	t_rgb	*color;
}				t_cylinder;

typedef struct s_scene
{
	t_sphere		**sphere;
	t_plane			**plane;
	t_cylinder		**cylinder;
	t_amb			*ambient;
	t_spot			*light;
	t_cam			*camera;
	//t_rescam		*var;
	t_coord			*axis;
	float			*var;
	int				x_screen;
	int				y_screen;
	struct s_data	*data;
}				t_scene;

typedef struct s_glob
{
	t_scene	*scene;
}				t_glob;

#endif
