#include <stdio.h>
#include "../HDRS/calcul.h"

void	t_eq_sec_deg(void)
{
	if (_eq_sec_deg(0, 0, 0) != 0)
		printf("_eq_sec_deg test 1 failed\n");
	if (_eq_sec_deg(1, -5, 6) != 2)
		printf("_eq_sec_deg test 2 failed\n");
	if (_eq_sec_deg(2, -3, -2) != 2)
		printf("_eq_sec_deg test 3 failed\n");
	if (_eq_sec_deg(1, 4, 4) >= 0)
		printf("_eq_sec_deg test 4 failed\n");
	if (_eq_sec_deg(1, 0, 1) != 0)
		printf("_eq_sec_deg test 5 failed\n");
}

void	t_direct_axis(void)
{
	t_scene test1;

	test1.fov = 70;
	test1.dov[0] = 1;
	test1.dov[1] = 0;
	test1.dov[2] = 0;
	test1.x_screen = 1920;
	test1.y_screen = 1080;

	t_scene test2;

	test2.fov = 70;
	test2.dov[0] = 0;
	test2.dov[1] = 1;
	test2.dov[2] = 0;
	test2.x_screen = 1920;
	test2.y_screen = 1080;

	t_scene test3;

	test3.fov = 70;
	test3.dov[0] = 1;
	test3.dov[1] = 1;
	test3.dov[2] = 1;
	test3.x_screen = 1920;
	test3.y_screen = 1080;

	t_scene test4;

	test4.fov = 160;
	test4.dov[0] = 1;
	test4.dov[1] = 0;
	test4.dov[2] = 0;
	test4.x_screen = 1920;
	test4.y_screen = 1080;

	if (_direct_axis(&test1, 960, 540, 0) != )

}