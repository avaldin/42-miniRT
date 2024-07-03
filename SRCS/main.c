/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:42:23 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 17:30:05 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/pixel.h"
#include "../HDRS/calcul.h"
#include <stdio.h>
#include "../include/libft/libft.h"
#include <fcntl.h>
#include "../include/minilibx-linux/mlx.h"

int	main(void)
{
	t_struct	g;
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->scene = _parsing(data->scene);
	g.img = data;
	data->scene->data = data;
	_set_vars_img(&g, SCREEN_X, SCREEN_Y);
	_generate_image(data->scene);
	printf("hehe\n");
	_window(&g);
	return (0);
}