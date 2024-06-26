/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:40:56 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/26 11:26:35 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(const char *nptr)
{
	int		i;
	float	pre;
	float	post;

	i = 0;
	pre = (float)ft_atoi(nptr);
	while (nptr[i] != '.')
		++i;
	if (!nptr)
		return (pre);
	++i;
	post = (float)ft_atoi(&nptr[i]);
	while (post > 1)
		post /= 10.;
	return (pre + post);
}
