#include "main.h"

int mandelbrot(t_complex c)
{
	t_complex	z;
	int			i;

  z.re = 0;
  z.im = 0;
	i = 0;
	while ((z.re * z.re + z.im * z.im) <= 4.0 && i < MAX_ITER)
	{
		z = complex_add(complex_mul(z, z), c);
		i++;
	}
	return (i);
}
