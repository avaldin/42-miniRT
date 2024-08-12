/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:26:25 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/17 00:33:43 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <stdlib.h>
#include <unistd.h>

void	_strerror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	write(2, str, i);
	write(2, "\n", 1);
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
	while (line[i] && (line[i] == 32 || line[i] == '\n'))
		++i;
	return (&line[i]);
}
