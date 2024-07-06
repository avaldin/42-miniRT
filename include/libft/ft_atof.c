/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:40:56 by tmouche           #+#    #+#             */
/*   Updated: 2024/07/05 01:01:13 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *nptr)
{
	int		i;
	float	pre;
	float	post;

	if (!nptr)
		return (0.);
	i = 0;
	pre = (float)ft_atoi(nptr);
	while (nptr[i] && nptr[i] != '.')
		++i;
	if (!nptr)
		return (pre);
	++i;
	post = (float)ft_atoi(&nptr[i]);
	while (post > 1)
		post /= 10.;
	if (pre < 0)
		return (pre - post);
	return (pre + post);
}
