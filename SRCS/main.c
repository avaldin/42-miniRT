/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:42:23 by avaldin           #+#    #+#             */
/*   Updated: 2024/07/20 03:19:26 by tmouche          ###   ########.fr       */
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

	if (_check_args(argc, argv) == FAILURE)
		return (0);
	data.scene = _extract_data(argv[1]);
	if (!data.scene)
		return (1);
	data.window = &window;
	if (_init_mvt_struct(&kinetic, data.scene->camera) == FAILURE)
		return (1);
	data.kinetic = &kinetic;
	_displaying(&data);
	return (0);
}