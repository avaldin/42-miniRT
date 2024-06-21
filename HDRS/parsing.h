/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:02:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/22 00:49:51 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
#include "structure.h"
#define BUFFER_SIZE 100

char	*get_next_line(int fd);
t_check	_check_args(int	argc, char **argv);

#endif