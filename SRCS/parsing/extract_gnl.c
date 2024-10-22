/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:02 by tmouche           #+#    #+#             */
/*   Updated: 2024/10/22 22:05:44 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

static void	_reset_buff(char *buff, _Bool all)
{
	size_t	index;
	size_t	offset;

	if (!buff[0])
		return ;
	index = 1;
	while (buff[index] && buff[index - 1] != '\n' && all == 0)
		index++;
	offset = 0;
	while (buff[index] && all == 0)
		buff[offset++] = buff[index++];
	while (buff[offset])
		buff[offset++] = 0;
}

static char	*_buffncpy(char *buff, size_t size)
{
	char	*cpy;
	size_t	index;

	if (!buff)
		return (NULL);
	cpy = malloc(sizeof(char) * (size + 1));
	if (!cpy)
		return (NULL);
	index = 0;
	while (buff[index] && index < size)
	{
		cpy[index] = buff[index];
		++index;
	}
	cpy[index] = 0;
	_reset_buff(buff, 0);
	return (cpy);
}

static char	*_setbuff(char *act_line, char *buff)
{
	char	*new_line;
	char	temp;
	ssize_t	size;
	_Bool	stop;

	size = ft_strlen(buff, '\n') + 1;
	stop = 0;
	if (size != BUFFER_SIZE)
	{
		temp = buff[size];
		buff[size] = 0;
		stop = 1;
	}
	new_line = ft_strjoin(act_line, buff);
	if (stop)
		buff[size] = temp;
	if (act_line)
		free (act_line);
	if (!new_line)
		return (NULL);
	_reset_buff(buff, 0);
	return (new_line);
}

static char	*_create_new_line(int fd, char *buff)
{
	char	*line;
	ssize_t	size;

	line = NULL;
	size = BUFFER_SIZE;
	while (size == BUFFER_SIZE && !ft_strrchr(line, '\n'))
	{
		line = _setbuff(line, buff);
		if (!line)
			return (_reset_buff(buff, 1), NULL);
		if (ft_strrchr(line, '\n'))
			break ;
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0)
			return (free (line), _reset_buff(buff, 1), NULL);
		if (size < BUFFER_SIZE && size > 0)
			line = _setbuff(line, buff);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		size;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buff[0])
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size <= 0)
			return (NULL);
		buff[BUFFER_SIZE] = 0;
	}
	if (ft_strrchr(buff, '\n'))
		line = _buffncpy(buff, ft_strlen(buff, '\n') + 1);
	else
		line = _create_new_line(fd, buff);
	return (line);
}
