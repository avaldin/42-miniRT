/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_extract_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 01:11:58 by thibaud           #+#    #+#             */
/*   Updated: 2024/06/22 18:17:37 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include <fcntl.h>
#include <errno.h>

void	_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free (tab[i++]);
	free (tab);
}

static char **_read_file(int fd)
{
	char	**res;
	char	**t_map;
	char	*t_str;
	
	res = NULL;
	t_map = NULL;
	while (42)
	{
		errno = 0;
		t_str = get_next_line(fd);
		if (!t_str && errno)
			return (_freetab(res), perror(NULL), NULL);
		else if (!t_str)
			break ;
		if (!ft_strfull(t_str, 9, 13))
		{
			t_map = ft_stradd(res, t_str);
			if (!t_map)
				return (_freetab(res), free (t_str), perror(NULL), NULL);
		}
		else
			free (t_str);
		res = t_map;
	}
	return (t_map);
}

t_scene	*_extract_data(char	*path_file)
{
	t_scene	*settings;
	char	**data;
	int		fd;

	fd = open(path_file, O_WRONLY);
	if (fd < 0)
		return (perror(NULL), NULL);
	data = _read_file(fd);
	close (fd);
	if (!data)
		return (NULL);
	for (int i = 0; data[i]; i++)
		printf("%s\n", data[i]);
	settings = NULL;
	return (settings);
}