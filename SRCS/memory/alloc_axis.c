/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_axis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:58:18 by tmouche           #+#    #+#             */
/*   Updated: 2024/08/20 03:58:20 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structure.h"

void	_free_axis(t_coord ***axis, int i, int j)
{
	while (i > -1)
	{
		while (j > 0)
			free(axis[i][j--]);
		free(axis[i]);
		i--;
	}
	free(axis);
}
