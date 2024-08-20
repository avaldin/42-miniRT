/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:42:23 by avaldin           #+#    #+#             */
/*   Updated: 2024/08/14 01:20:01 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/displaying.h"
#include "../HDRS/calcul.h"
#include "libft.h"
#include "../HDRS/parsing.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_glob	data;
	t_wdw	window;
	t_kntc	kinetic;
	t_menu	menu;

	if (_check_args(argc, argv) == FAILURE)
		return (0);
	data.scene = _extract_data(argv[1]);
	if (!data.scene)
		return (1);
	data.window = &window;
	if (_init_mvt_struct(&kinetic, data.scene->camera) == FAILURE)
		return (1);
	data.kinetic = &kinetic;
	data.menu = &menu;
	_displaying(&data);
	return (0);
}