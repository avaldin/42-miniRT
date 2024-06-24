/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:02:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/24 18:51:56 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# define _NO_A "ARGUMENT NOT FOUND"
# define _2BIG_A "TOO MUCH ARGUMENTS"
# define _NOK_A "ARGUMENT NOT KNOWN"
# define _NOK_ID "IDENTIFIER NOT KNOWN"
# include "structure.h"
# define BUFFER_SIZE 100

/* ***********************************UTILS*********************************** */
void	_freetab(char **tab);
void	_strerror(char *str);
char	*_is_space(char *line);
char	*_until_char(char *line, char c);
char	*_is_inrange(char *line, char r_bot, char r_top);

t_check	_check_rgb(t_rgb *colors);
t_rgb	*_set_rgb(char *line);
t_check	_init_ambient(t_amb *ambient, char *line);

char	*get_next_line(int fd);
t_scene	*_extract_data(char	*path_file);
t_check	_check_args(int	argc, char **argv);

#endif