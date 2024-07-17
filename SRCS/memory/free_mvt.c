/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mvt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:32:03 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 17:34:36 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <stdlib.h>

void	_free_mvt(t_mvt *kinetic)
{
	if (!kinetic)
		return ;
	if (kinetic->dir_x)
		free (kinetic->dir_x);
	if (kinetic->dir_y)
		free (kinetic->dir_y);
	if (kinetic->dir_bx)
		free (kinetic->dir_bx);
	if (kinetic->dir_by)
		free (kinetic->dir_by);
}
