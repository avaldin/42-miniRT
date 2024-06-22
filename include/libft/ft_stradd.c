/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:11:41 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/22 23:39:02 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_stradd(char **map, char *add)
{
	char	**new;
	int		i;
	
	i = 0;
	while (map && map[i])
		++i;
	new = ft_calloc(sizeof(char *), (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (map && map[i])
	{
		new[i] = map[i];
		++i;
	}
	new[i] = add;
	return (new);
}