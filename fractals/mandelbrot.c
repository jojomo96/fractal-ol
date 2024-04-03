#include "../main.h"

int	calculate_max_iter(double zoom_level)
{
	if (zoom_level < 0.1)
		return (500);
	else if (zoom_level < 0.001)
		return (1000);
	else if (zoom_level < 0.00001)
		return (2000);
	return (MAX_ITER);
}

int	mandelbrot(t_complex c, double zoom_level)
{
	t_complex	z;
	int			i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while ((z.re * z.re + z.im * z.im) <= 4.0
		&& i < calculate_max_iter(zoom_level))
	{
		z = complex_add(complex_mul(z, z), c);
		i++;
	}
	return (i);
}
