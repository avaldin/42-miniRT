/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moovement.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:35:22 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/19 00:46:19 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOOVEMENT_H
# define MOOVEMENT_H
# include "structure.h"

t_check	_init_mvt_struct(t_mvt *kinetic, t_cam *cam);
void	_change_cam_pos(t_cam *cam, t_coord *matrix, float mv);
int		_moove_cam(t_glob *data);

#endif