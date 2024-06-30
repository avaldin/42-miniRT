/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaud <thibaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:07:00 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/30 15:33:33 by thibaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.h"
#include "parsing.h"
#include "structure.h"
#include "colors.h"

void	_print_scene(t_scene *settings)
{
	int	i;

	printf("amb [ratio] : (%f)\n", settings->ambient->ratio);
	printf("amb [colors RED] : (%d)\n", settings->ambient->color->red);
	printf("amb [colors GREEN] : (%d)\n", settings->ambient->color->green);
	printf("amb [colors BLUE] : (%d)\n", settings->ambient->color->blue);
	printf("***********************\n");
	printf("cam [fov] : (%d)\n", settings->camera->fov);
	printf("cam [pos x] : (%f)\n", settings->camera->pos->x);
	printf("cam [pos y] : (%f)\n", settings->camera->pos->y);
	printf("cam [pos z] : (%f)\n", settings->camera->pos->z);
	printf("cam [vect x] : (%f)\n", settings->camera->vect->x);
	printf("cam [vect y] : (%f)\n", settings->camera->vect->y);
	printf("cam [vect z] : (%f)\n", settings->camera->vect->z);
	printf("***********************\n");
	printf("spot [ratio] : (%f)\n", settings->light->ratio);
	printf("spot [pos x] : (%f)\n", settings->light->pos->x);
	printf("spot [pos y] : (%f)\n", settings->light->pos->y);
	printf("spot [pos z] : (%f)\n", settings->light->pos->z);
	printf("spot [colors RED] : (%d)\n", settings->light->color->red);
	printf("spot [colors GREEN] : (%d)\n", settings->light->color->green);
	printf("spot [colors BLUE] : (%d)\n", settings->light->color->blue);
	printf("***********************\n");
	i = 0;
	while (settings->sphere && settings->sphere[i])
	{
		printf("sphere n°%d [diameter] : (%f)\n", i, settings->sphere[i]->diameter);
		printf("sphere n°%d [pos x] : (%f)\n", i, settings->sphere[i]->pos->x);
		printf("sphere n°%d [pos y] : (%f)\n", i, settings->sphere[i]->pos->y);
		printf("sphere n°%d [pos z] : (%f)\n", i, settings->sphere[i]->pos->z);
		printf("sphere n°%d [colors RED] : (%d)\n", i, settings->sphere[i]->color->red);
		printf("sphere n°%d [colors GREEN] : (%d)\n", i, settings->sphere[i]->color->green);
		printf("sphere n°%d [colors BLUE] : (%d)\n", i, settings->sphere[i]->color->blue);
		printf("***********************\n");
		++i;
	}
	i = 0;
	while (settings->plane && settings->plane[i])
	{
		printf("plane n°%d [pos x] : (%f)\n", i, settings->plane[i]->pos->x);
		printf("plane n°%d [pos y] : (%f)\n", i, settings->plane[i]->pos->y);
		printf("plane n°%d [pos z] : (%f)\n", i, settings->plane[i]->pos->z);
		printf("plane n°%d [vect x] : (%f)\n", i, settings->plane[i]->vect->x);
		printf("plane n°%d [vect y] : (%f)\n", i, settings->plane[i]->vect->y);
		printf("plane n°%d [vect z] : (%f)\n", i, settings->plane[i]->vect->z);
		printf("plane n°%d [colors RED] : (%d)\n", i, settings->plane[i]->color->red);
		printf("plane n°%d [colors GREEN] : (%d)\n", i, settings->plane[i]->color->green);
		printf("plane n°%d [colors BLUE] : (%d)\n", i, settings->plane[i]->color->blue);
		printf("***********************\n");
		++i;
	}
	i = 0;
	while (settings->cylinder && settings->cylinder[i])
	{
		printf("cylinder n°%d [height] : (%f)\n", i, settings->cylinder[i]->height);
		printf("cylinder n°%d [diameter] : (%f)\n", i, settings->cylinder[i]->diameter);
		printf("cylinder n°%d [pos x] : (%f)\n", i, settings->cylinder[i]->pos->x);
		printf("cylinder n°%d [pos y] : (%f)\n", i, settings->cylinder[i]->pos->y);
		printf("cylinder n°%d [pos z] : (%f)\n", i, settings->cylinder[i]->pos->z);
		printf("cylinder n°%d [vect x] : (%f)\n", i, settings->cylinder[i]->vect->x);
		printf("cylinder n°%d [vect y] : (%f)\n", i, settings->cylinder[i]->vect->y);
		printf("cylinder n°%d [vect z] : (%f)\n", i, settings->cylinder[i]->vect->z);
		printf("cylinder n°%d [colors RED] : (%d)\n", i, settings->cylinder[i]->color->red);
		printf("cylinder n°%d [colors GREEN] : (%d)\n", i, settings->cylinder[i]->color->green);
		printf("cylinder n°%d [colors BLUE] : (%d)\n", i, settings->cylinder[i]->color->blue);
		printf("***********************\n");
		++i;
	}
}

void	t_check_files_A(void)
{
	t_amb *amb;
	
	if (_init_ambient(&amb, "A") == SUCCESS)
		printf("%stest number 1 failed%s\n", RED, RESET);
	if (_init_ambient(&amb, "A") == SUCCESS)
		printf("%stest number 1 failed%s\n", RED, RESET);
}

void	t_check_args(void)
{
	char *test1[] = {"./test", "miniRT", NULL};
	char *test2[] = {"./test", "T.rt", NULL};
	char *test3[] = {"./test", ".rt", NULL};
	char *test4[] = {"./test", "", NULL};
	char *test5[] = {"./test", NULL};
	char *test6[] = {"./test", "miniRT.rt", "miniRT.rt", NULL};
	char *test7[] = {"./test", "miniRT.rt", NULL};

	if (_check_args(2, test1) == SUCCESS)
		printf("%stest number 1 failed%s\n", RED, RESET);
	if (_check_args(2, test2) == FAILURE)
		printf("%stest number 2 failed%s\n", RED, RESET);
	if (_check_args(2, test3) == SUCCESS)
		printf("%stest number 3 failed%s\n", RED, RESET);
	if (_check_args(2, test4) == SUCCESS)
		printf("%stest number 4 failed%s\n", RED, RESET);
	if (_check_args(1, test5) == SUCCESS)
		printf("%stest number 5 failed%s\n", RED, RESET);
	if (_check_args(3, test6) == SUCCESS)
		printf("%stest number 6 failed%s\n", RED, RESET);
	if (_check_args(2, test7) == FAILURE)
		printf("%stest number 6 failed%s\n", RED, RESET);
}