/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 00:33:32 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 18:23:48 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structure.h"
#include "memory.h"

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

void	_free_n_exit(t_glob *data, char *err)
{
	_free_mvt(data->kinetic);
	_free_window(data->window);
	_free_scene(data->scene, err);
	if (!err)
		exit (EXIT_SUCCESS);
	exit (EXIT_FAILURE);
}