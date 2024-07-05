/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:50:15 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 17:57:22 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stddef.h>

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}				t_coord;

typedef struct	s_plane
{
	float	pos[3];
	float	vect[3];
	int		color[3];
}				t_plane;

typedef struct s_sphere
{
	float	radius;
	t_coord	*pos;
//	t_rgb	*color;
}				t_sphere;

typedef struct	s_cylinder
{
	float	pos[3];
	float	vect[3];
	float	diameter;
	float	height;
	int		color[3];
}				t_cylinder;


//typedef struct	s_scene
//{
//	t_sphere		**sphere;
//	t_plane			**plane;
//	t_cylinder 		**cylinder;
//	float			pov[3];
//	float			dov_x[3];
//	float			dov_y[3];
//	float			dov_z[3];
//	float			fov;
//	float			*var;
//	int				fd;
//	int				x_screen;
//	int				y_screen;
//	struct s_data	*data;
//}				t_scene;

typedef struct s_cam
{
	int		fov;
	t_coord	*pos;
	t_coord	*vect;
}				t_cam;

typedef struct s_scene
{
	t_sphere		**sphere;
//	t_plane			**plane;
//	t_cylinder		**cylinder;
//	t_amb			*ambient;
//	t_spot			*light;
	t_cam			*camera;
//	t_coord			*dov_x;
//	t_coord			*dov_y;
	float			*var;
	int				x_screen;
	int				y_screen;
	struct s_data	*data;
}				t_scene;

typedef enum
{
	FAIL,
	SUCCESS
}				e_test;

t_scene	*_parsing(t_scene *scene);


#endif
