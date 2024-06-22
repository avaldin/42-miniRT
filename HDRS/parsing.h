/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:02:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/22 18:04:57 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
#include "structure.h"
#define BUFFER_SIZE 100

char	*get_next_line(int fd);
t_scene	*_extract_data(char	*path_file);
t_check	_check_args(int	argc, char **argv);

#endif