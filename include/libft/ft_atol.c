/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:32:56 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/24 19:33:21 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_atol(const char *nptr)
{
	size_t	i;
	size_t	result;
	int		sign;

	i = -1;
	sign = 1;
	result = 0;
	while ((nptr[++i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		;
	if (nptr[i] == 45 || nptr[i] == 43)
		if (nptr[i++] == 45)
			sign *= -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
		result = result * 10 + (nptr[i++] - 48);
	return (result * sign);
}