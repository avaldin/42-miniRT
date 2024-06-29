/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:25 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/27 13:28:37 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdio.h>

static inline t_check	_check_extention(char *arg)
{
	int	index;

	index = 0;
	while (arg[index])
		++index;
	if (index < 4)
		return (FAILURE);
	if (ft_strncmp(&arg[index - 3], ".rt", 3))
		return (FAILURE);
	return (SUCCESS);
}

t_check	_check_args(int argc, char **argv)
{
	if (argc < 2)
		printf("%s\n", _NO_A);
	else if (argc > 2)
		printf("%s\n", _2BIG_A);
	else if (_check_extention(argv[1]) == FAILURE)
		printf("%s\n", _NOK_A);
	else
		return (SUCCESS);
	return (FAILURE);
}
