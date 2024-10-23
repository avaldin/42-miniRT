/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:40:56 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/23 18:57:20 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static float	give_part(const char *nptr)
{
	int		i;
	float	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0.;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		++i;
	if (nptr[i] == 45 || nptr[i] == 43)
		if (nptr[i++] == 45)
			sign *= -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
		result = result * 10 + (nptr[i++] - 48);
	return (result * sign);
}

float	ft_atof(const char *nptr)
{
	int		i;
	float	pre;
	float	post;

	if (!nptr)
		return (0.);
	i = 0;
	pre = give_part(nptr);
	while (nptr[i] && nptr[i] != '.')
		++i;
	if (!nptr)
		return (pre);
	++i;
	post = give_part(&nptr[i]);
	while (post >= 1)
		post /= 10.;
	if (pre < 0)
		return (pre - post);
	return (pre + post);
}
