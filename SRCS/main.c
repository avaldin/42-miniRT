/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:17:56 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/27 13:28:05 by tmouche          ###   ########.fr       */
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
