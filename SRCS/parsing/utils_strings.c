/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:26:25 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/23 14:04:00 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <stdlib.h>
#include <unistd.h>

void	_strerror(char *str)
{
	int	i;
	int	err[3];

	i = 0;
	while (str[i])
		++i;
	err[0] = write(2, "Error: ", 8);
	err[1] = write(2, str, i);
	err[2] = write(2, "\n", 1);
	i = 0;
	while (i < 3)
	{
		if (err[i] == -1)
			return ;
		++i;
	}
}

char	*_until_char(char *line, char c)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (NULL);
	while (line[i] && line[i] != c)
		++i;
	return (&line[i]);
}

char	*_is_inrange(char *line, char r_bot, char r_top)
{
	int	i;

	if (!line || !*line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] >= r_bot && line[i] <= r_top)
		++i;
	return (&line[i]);
}

char	*_is_space(char *line)
{
	int	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && ((line[i] == 32
				|| (line[i] >= 9 && line[i] <= 13))))
		++i;
	return (&line[i]);
}
