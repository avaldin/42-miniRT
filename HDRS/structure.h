/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche < tmouche@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:21:44 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/16 19:27:25 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include <stddef.h>
# include <errno.h>
# define X_SSIZE 1920
# define Y_SSIZE 1080

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
/*               PARS DATA                                                    */
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
/*               SETTINGS                                                     */
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
/*               OBJET                                                        */
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

/* ************************************************************************** */
/*               WINDOW                                                       */
/* ************************************************************************** */

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_scene			*scene;
}					t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_wdw
{
	t_vars			*vars;
	t_img			*img;
}				t_wdw;

/* ************************************************************************** */
/*               GLOBAL                                                       */
/* ************************************************************************** */

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
}				t_scene;

typedef struct s_glob
{
	t_scene	*scene;
	t_wdw	*window;
}				t_glob;

#endif
