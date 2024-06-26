/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:26:25 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/26 13:02:34 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	_strerror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	write(2, str, i);	
}

void	_freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free (tab[i++]);
	free (tab);
}

char	*_is_inrange(char *line, char r_bot, char r_top)
{
	int	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] >= r_bot && line[i] <= r_top)
		++i;
	return (&line[i]);
}

char	*_until_char(char *line, char c)
{
	int	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != c)
		++i;
	return (&line[i]);
}

char	*_is_space(char *line)
{
	int	i;
	
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && (line[i] == 32 || line[i] == '\n'))
		++i;
	return (&line[i]);
}
