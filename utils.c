#include "main.h"

t_complex	init_complex(double re, double im)
{
	t_complex	c;

	c.re = re;
	c.im = im;
	return (c);
}

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}
