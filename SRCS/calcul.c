/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:35 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 17:13:11 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../HDRS/structure.h"
#include "../include/libft/libft.h"

float	*_eq_sec_deg(float a, float b, float c)
{
	float	*result;

	if (powf(b, 2) - 4 * a * c < 0 || !a)
		return (NULL);
	result = ft_calloc(2, sizeof(float));
	if (!result)
		exit(50);
	result[0] = (-b - sqrtf(powf(b, 2) - 4 * a * c)) / (2 * a);
	result[1] = (-b + sqrtf((powf(b, 2) - 4 * a * c))) / (2 * a);
	return (result);
}