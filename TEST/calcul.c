#include <stdio.h>
#include "../HDRS/calcul.h"

void	t_eq_sec_deg(void)
{
	if (_eq_sec_deg(0, 0, 0) != NULL)
		printf("_eq_sec_deg test 1 failed\n");
	if (!_eq_sec_deg(1, -5, 6) || _eq_sec_deg(1, -5, 6)[0] != 2 || _eq_sec_deg(1, -5, 6)[1] != 2 || _eq_sec_deg(1, -5, 6)[2] != 3)
		printf("_eq_sec_deg test 2 failed\n");
	if (!_eq_sec_deg(2, -3, -2) || _eq_sec_deg(2, -3, -2)[0] != 2 || _eq_sec_deg(2, -3, -2)[1] != -0.5 || _eq_sec_deg(2, -3, -2)[2] != 2)
		printf("_eq_sec_deg test 3 failed\n");
	if (!_eq_sec_deg(1, 4, 4) || _eq_sec_deg(1, 4, 4)[0] != 2 || _eq_sec_deg(1, 4, 4)[1] != -2)
		printf("_eq_sec_deg test 4 failed : %lf\n",   _eq_sec_deg(1, 4, 4)[1]);
	if (_eq_sec_deg(1, 0, 1) != NULL)
		printf("_eq_sec_deg test 5 failed\n");
}