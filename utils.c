#include "main.h"

t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

int	calculate_max_iter(double zoom_level)
{
	double	iter_scale;
	double	iter;

	iter_scale = 1.0 / zoom_level;
	iter = log(iter_scale) * 100.0;
	iter = floor(iter);
	if (iter < 100)
	{
		iter = 100;
	}
	else if (iter > MAX_ITER)
	{
		iter = MAX_ITER;
	}
	return ((int)iter);
}
