/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mvt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:32:03 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/25 21:51:54 by tmouche          ###   ########.fr       */
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
}
