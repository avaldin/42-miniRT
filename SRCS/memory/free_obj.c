/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:17:23 by thibaud           #+#    #+#             */
/*   Updated: 2024/10/02 18:48:48 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <stdlib.h>

void	_free_sphere(t_sphere **sph)
{
	int	i;

	if (!sph)
		return ;
	i = 0;
	while (sph[i])
	{
		free ((sph[i])->pos);
		free ((sph[i])->color);
		free ((sph[i])->r_pos);
		free (sph[i]);
		++i;
	}
	free (sph);
}

void	_free_plane(t_plane **pla)
{
	int	i;

	if (!pla)
		return ;
	i = 0;
	while (pla[i])
	{
		free ((pla[i])->pos);
		free ((pla[i])->vect);
		free ((pla[i])->color);
		free (pla[i]);
		++i;
	}
	free (pla);
}

void	_free_cylinder(t_cylinder **cyl)
{
	int	i;

	if (!cyl)
		return ;
	i = 0;
	while (cyl[i])
	{
		free ((cyl[i])->pos);
		free ((cyl[i])->vect);
		free ((cyl[i])->color);
		free (cyl[i]);
		++i;
	}
	free (cyl);
}
