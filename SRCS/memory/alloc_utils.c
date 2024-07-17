/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:01:16 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 17:20:43 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <stdlib.h>

t_coord	*_alloc_coord(float x, float y, float z)
{
	t_coord	*res;

	res = malloc(sizeof(t_coord));
	if (!res)
		return (NULL);
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}

t_rgb	*_alloc_rgb(int red, int green, int blue)
{
	t_rgb	*res;

	res = malloc(sizeof(t_rgb));
	if (!res)
		return (NULL);
	res->red = red;
	res->green = green;
	res->blue = blue;
	return (res);
}
