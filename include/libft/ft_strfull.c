/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:26:01 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/22 17:35:12 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfull(const char *s, int lower, int upper)
{
	size_t	i;

	i = -1;
	while (s[++i])
		if (s[i] < (unsigned char)lower || s[i] > (unsigned char)upper)
			return (&((char *)s)[i]);
	return (0);
}
