#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>


static double const precision = 1.0e-6;

double Derivative(double complex (*F)(complex double), double complex x)
{
	double complex xPh = x + precision;

	double complex result = (F(xPh) - F(x)) / precision;

	//printf("here is the original x point %f\n", x);
	//printf("here is the slightly more x point %f\n", xPh);

	return result;
}

double IsPrecise(double x, double y, double precision)
{
	return cabs(x - y) < precision;
}


int main(void)
{
	printf("%f\n", precision);

	double complex num = 32 * I;
	
	// csqrt test
	double complex testNs = csqrt(num); 
	double complex testDs = Derivative(csqrt, num);

	printf("linear test of %g + %g I with F(): %g + %g I and F`(): %g + %g I\n",
			creal(num), cimag(num), 
			creal(testNs), cimag(testNs),
			creal(testDs), cimag(testDs));

	return 0;
}