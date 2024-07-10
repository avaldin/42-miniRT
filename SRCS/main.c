/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:42:23 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/07 01:32:34 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/pixel.h"
#include "../HDRS/calcul.h"
#include "../include/libft/libft.h"
#include "../HDRS/parsing.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_struct	g;
	t_glob		data;

	if (_check_args(argc, argv) == FAILURE)
		return (0);
	data.scene = _extract_data(argv[1]);
	_set_vars_img(&g, X_SCREEN_SIZE, Y_SCREEN_SIZE);
	data.scene->data = g.img;
	_generate_image(data.scene);
	_window(&g);
	return (0);
}