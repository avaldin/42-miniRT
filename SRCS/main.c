/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:17:56 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/22 18:07:33 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main(int argc, char **argv)
{
	
	if (_check_args(argc, argv) == FAILURE)
		return (0);
	_extract_data(argv[1]);
	return (1);
}