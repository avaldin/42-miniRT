/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:42:23 by avaldin           #+#    #+#             */
/*   Updated: 2024/06/19 17:30:05 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HDRS/structure.h"
#include "../HDRS/calcul.h"

int	main(void)
{
	t_data	data;

	_parsing(&data);
	_generate_image(&data);
	return (0);
}