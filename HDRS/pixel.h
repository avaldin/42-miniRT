/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:54:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/07 01:14:18 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H
# include "structure.h"

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_scene			*scene;
}					t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_struct
{
	t_vars			*vars;
	t_data			*img;
}				t_struct;


void	_mlx_pixel_put(t_data *data, int x, int y, int color);
void	_set_vars_img(t_struct *g, int x, int y);
void	_window(t_struct *g);

#endif