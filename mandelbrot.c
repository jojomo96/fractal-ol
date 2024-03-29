#include "main.h"

int mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;

  z.re = 0;
  z.im = 0;
	i = 0;
	while (complex_abs(z) <= 2.0 && i < max_iter)
	{
		z = complex_add(complex_mul(z, z), c);
		i++;
	}
	return (i);
}
