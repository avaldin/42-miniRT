/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:07:00 by tmouche           #+#    #+#             */
/*   Updated: 2024/06/24 11:19:53 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "test.h"
#include "parsing.h"
#include "structure.h"
#include "colors.h"

// void	t_check_files(void)
// {
// 	if (_)
// }

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