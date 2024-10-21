/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:22:24 by avaldin           #+#    #+#             */
/*   Updated: 2024/10/21 11:30:30 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../HDRS/calcul.h"

void	_lateral_normal_cylinder(t_cylinder *cylinder,
							t_coord *v_normal, t_coord inter)
{
	t_coord	proj;

	v_normal->x = inter.x - cylinder->r_pos->x;
	v_normal->y = inter.y - cylinder->r_pos->y;
	v_normal->z = inter.z - cylinder->r_pos->z;
	proj.x = cylinder->r_vect->x * (v_normal->x * cylinder->r_vect->x
			+ v_normal->y * cylinder->r_vect->y
			+ v_normal->z * cylinder->r_vect->z);
	proj.y = cylinder->r_vect->y * (v_normal->x * cylinder->r_vect->x
			+ v_normal->y * cylinder->r_vect->y
			+ v_normal->z * cylinder->r_vect->z);
	proj.z = cylinder->r_vect->z * (v_normal->x * cylinder->r_vect->x
			+ v_normal->y * cylinder->r_vect->y
			+ v_normal->z * cylinder->r_vect->z);
	v_normal->x = v_normal->x - proj.x;
	v_normal->y = v_normal->y - proj.y;
	v_normal->z = v_normal->z - proj.z;
}

void	_normal_cylinder(t_cylinder *cylinder, t_coord *v_normal, t_coord inter)
{
	if (cylinder->part == 2)
	{
		v_normal->x = cylinder->r_vect->x;
		v_normal->y = cylinder->r_vect->y;
		v_normal->z = cylinder->r_vect->z;
	}
	else if (cylinder->part == 3)
	{
		v_normal->x = -cylinder->r_vect->x;
		v_normal->y = -cylinder->r_vect->y;
		v_normal->z = -cylinder->r_vect->z;
	}
	else
		_lateral_normal_cylinder(cylinder, v_normal, inter);
}
