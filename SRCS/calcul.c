/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:35 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 17:37:41 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../HDRS/structure.h"
#include "../include/libft/libft.h"

float	distance(float a[3], float b[3])
{
	return (sqrtf(powf(b[2] - a[2], 2) + powf(b[2] - a[2], 2)
			+ powf(b[2] - a[2], 2)));
}

float	_eq_sec_deg(float a, float b, float c)
{
	float	result_a;
	float	result_b;

	if (powf(b, 2) - 4 * a * c < 0 || !a)
		return (-1);
	result_a = (-b - sqrtf(powf(b, 2) - 4 * a * c)) / (2 * a);
	result_b = (-b + sqrtf((powf(b, 2) - 4 * a * c))) / (2 * a);
	if ((result_a >= 0 && result_a < result_b) || result_b < 0)
		return (result_a);
	return (result_b);
}
