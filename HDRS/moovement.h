/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moovement.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:35:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 18:57:18 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOOVEMENT_H
# define MOOVEMENT_H
# include "structure.h"

t_check	_init_mvt_struct(t_mvt *kinetic, t_cam *cam);
void	_change_cam_pos(t_cam *cam, t_coord *matrix, float mv);
int		_moove_cam(t_glob *data);

#endif