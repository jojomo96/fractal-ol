
#ifndef COMPLEX_H
# define COMPLEX_H

# include <math.h>
typedef struct s_complex
{
	double re; // Real part
	double im; // Imaginary part
}			t_complex;

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sub(t_complex a, t_complex b);
t_complex	complex_mul(t_complex a, t_complex b);
double		complex_abs(t_complex z);

#endif
