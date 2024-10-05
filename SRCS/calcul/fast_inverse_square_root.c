#include <stdint.h>

float	f_isqrt(float number)
{
	int32_t	i;
	float	x2;
	float	y;
	float	threehalfs;

	y = 0.0F;
	threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = * (int32_t *) &y;
	i = 0x5f3759df - (i >> 1);
	y = * (float *) &i;
	y = y * (threehalfs - (x2 * y * y));
	return (y);
}
