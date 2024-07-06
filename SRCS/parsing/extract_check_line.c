/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_check_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:54:56 by thibaud           #+#    #+#             */
/*   Updated: 2024/06/30 15:55:25 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_check	_is_point(char *line, int i)
{
	if (i == 0)
		return (FAILURE);
	if (!(line[i - 1] >= '0' && line[i - 1] <= '9'))
		return (FAILURE);
	if (!(line[i + 1] >= '0' && line[i + 1] <= '9'))
		return (FAILURE);
	return (SUCCESS);
}

static t_check	_is_coma(char *line, int i)
{
	if (i == 0)
		return (FAILURE);
	if (!(line[i - 1] >= '0' && line[i - 1] <= '9'))
		return (FAILURE);
	if (!(line[i + 1] >= '0' && line[i + 1] <= '9'))
		if (line[i + 1] != '-')
			return (FAILURE);
	return (SUCCESS);
}

static t_check	_is_minus(char *line, int i)
{
	if (!(line[i + 1] >= '0' && line[i + 1] <= '9'))
		return (FAILURE);
	return (SUCCESS);
}

t_check	check_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == ' ' || line[i] == '\n' || (line[i] >= '0' && line[i] <= '9'))
			;
		else if (line[i] == '.' && _is_point(line, i))
			return (FAILURE);
		else if (line[i] == ',' && _is_coma(line, i))
			return (FAILURE);
		else if (line[i] == '-' && _is_minus(line, i))
			return (FAILURE);
		else if (line[i] != '-' && line[i] != ',' && line[i] != '.')
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}