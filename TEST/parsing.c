#include "test.h"


void	t_parsing(void)
{
	char *test1[] = {"miniRT", NULL};
	char *test2[] = {"miniRT", "test.rt", NULL};

	if (parsing(1, test1) == SUCCESS)
		printf("test number 1 failed\n");

	if (parsing(2, test2) == FAIL)
		printf("test number 2 failed\n");
}