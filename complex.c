
#include "complex.h"

// Adds two complex numbers
t_complex complex_add(t_complex a, t_complex b) {
    t_complex result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

// Subtracts two complex numbers
t_complex complex_sub(t_complex a, t_complex b) {
    t_complex result;
    result.re = a.re - b.re;
    result.im = a.im - b.im;
    return result;
}

// Multiplies two complex numbers
t_complex complex_mul(t_complex a, t_complex b) {
    t_complex result;
    result.re = a.re * b.re - a.im * b.im;
    result.im = a.re * b.im + a.im * b.re;
    return result;
}

// Calculates the magnitude (absolute value) of a complex number
double complex_abs(t_complex z) {
    return sqrt(z.re * z.re + z.im * z.im);
}
