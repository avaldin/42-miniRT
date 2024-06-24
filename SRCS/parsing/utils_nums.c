/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:57:04 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/24 19:01:20 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structure.h"
#include "parsing.h"

t_check	_check_rgb(t_rgb *colors)
{
	if (!(colors->red >= 0 && colors->red <= 255)
		|| !(colors->green >= 0 && colors->green <= 255)
		|| !(colors->blue >= 0 && colors->blue <= 255))
		return (FAILURE);
	return (SUCCESS);
}

t_rgb	*_set_rgb(char *line)
{
	t_rgb	*res;

	res = malloc(sizeof(t_rgb));
	if (!res)
		return (NULL);
	res->red = 0;
	res->green = 0;
	res->blue = 0;
	if (!line)
		return (res);
	res->red = ft_atoi(line);
	line = _is_inrange(line, '0', '9');
	if (!line)
		return (res);
	res->green = ft_atoi(line);
	line = _is_inrange(line, '0', '9');
	if (!line)
		return (res);
	res->blue = ft_atoi(line);
	line = _is_space(_is_inrange(line, '0', '9'));
	if (line && *line != '\n')
		return (free(res), NULL);
	return (res);
}