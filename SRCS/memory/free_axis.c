/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_axis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:58:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/02 17:25:16 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structure.h"

void	_free_axis(t_coord ***axis)
{
	int	i;
	int	j;

	i = 0;
	while (axis[i])
	{
		j = 0;
		while (axis[i][j])
			free(axis[i][j++]);
		free(axis[i]);
		++i;
	}
	free(axis);
}
