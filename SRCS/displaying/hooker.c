/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:56:25 by thibaud           #+#    #+#             */
/*   Updated: 2024/07/17 02:54:30 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "memory.h"

int	_key_release(void *data)
{
	(void)data;
	return (SUCCESS);
}

int	_key_press(void *data)
{
	(void)data;
	return (SUCCESS);
}

int	_button_press(void *data)
{
	_free_n_exit(data, NULL);
	return (SUCCESS);
}