/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:21:44 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/28 13:57:37 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include <stddef.h>
# include <errno.h>
# define X_SSIZE 1500
# define Y_SSIZE 1000
# define SET_FRM 2500
# define TRUE 1
# define FALSE 0

struct	s_scene;
struct	s_coord;

typedef enum e_check
{
	SUCCESS,
	FAILURE
}			t_check;

typedef enum e_nwdw
{
	IN,
	OUT
}			t_nwdw;

typedef enum e_type
{
	OBJ_PLA,
	OBJ_SPH,
	OBJ_CYL,
	ENV_AMB,
	ENV_CAM,
	ENV_SPT
}			t_type;

typedef enum e_interface
{
	SCENE,
	MENU
}				t_interface;

typedef enum e_smenu
{
	FIRST_SCREEN,
	OBJET_SCREEN,
	CHANGE_SCREEN
}				t_smenu;

typedef enum e_mstate
{
	CONTINUE,
	STOP,
	ERROR,
	PASS
}			t_mstate;

typedef enum e_coordtype
{
	POS,
	VEC
}			t_coordtype;

/* ************************************************************************** */
/*               DATA                                                         */
/* ************************************************************************** */

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef struct s_rgb
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
	t_coord	*r_pos;
	t_coord	*vect;
}				t_cam;

typedef struct s_spot
{
	float	ratio;
	t_coord	*pos;
	t_coord	*r_pos;
	t_rgb	*color;
}				t_spot;

/* ************************************************************************** */
/*               OBJET                                                        */
/* ************************************************************************** */

typedef struct s_plane
{
	t_coord	*pos;
	t_coord	*r_pos;
	t_coord	*vect;
	t_coord	*r_vect;
	float	cst;
	t_rgb	*color;
}				t_plane;

typedef struct s_sphere
{
	float	radius;
	t_coord	*pos;
	t_coord	*r_pos;
	t_rgb	*color;
}				t_sphere;

typedef struct s_cylinder
{
	float	height;
	float	radius;
	int		part;
	t_coord	*pos;
	t_coord	*r_pos;
	t_coord	*vect;
	t_coord	*r_vect;
	t_rgb	*color;
}				t_cylinder;

/* ************************************************************************** */
/*               MOOVEMENT                                                    */
/* ************************************************************************** */

typedef struct s_rtn
{
	int		mv_x;
	int		mv_y;
	int		loc_x;
	int		loc_y;
}				t_rtn;

typedef struct s_mvt
{
	float	mv_x;
	float	mv_z;
	float	mv_y;
	t_coord	*dir_x;
}				t_mvt;

typedef struct s_kntc
{
	t_mvt	*cam_moov;
	t_rtn	*cam_rotate;	
}				t_kntc;

/* ************************************************************************** */
/*               MENU                                                         */
/* ************************************************************************** */

typedef struct s_button
{
	char	*name;
	int		csl_x;
	int		csl_y;
	int		cir_x;
	int		cir_y;
}				t_button;

typedef struct s_menu
{
	t_button	**menu;
	t_smenu		screen;
}				t_menu;

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
}					t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_wdw
{
	t_vars		*vars;
	t_img		*img;
	t_nwdw		box;
	t_interface	interf;
}				t_wdw;

/* ************************************************************************** */
/*               GLOBAL                                                       */
/* ************************************************************************** */

typedef struct s_scene
{
	t_cylinder		**cylinder;
	t_sphere		**sphere;
	t_plane			**plane;
	t_coord			***axis;
	t_spot			*light;
	t_amb			*ambient;
	t_cam			*camera;
	t_rgb			*rgb_object;
	float			*var;
	float			(*fct)(struct s_scene *, float, void *, struct s_coord *);
	void			*object;
	int				state;
}				t_scene;

typedef struct s_glob
{
	t_scene	*scene;
	t_menu	*menu;
	t_wdw	*window;
	t_kntc	*kinetic;
}				t_glob;

#endif
