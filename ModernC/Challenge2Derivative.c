#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static double const precision = 1.0e-6;

double Derivative(double (*F)(double), double x)
{
	double xPh = x + precision;

	double result = (F(xPh) - F(x)) / precision;

	//printf("here is the original x point %f\n", x);
	//printf("here is the slightly more x point %f\n", xPh);

	return result;
}

double IsPrecise(double x, double y, double precision)
{
	return fabs(x - y) < precision;
}

double Linear(double x)
{	
	double result = (x * 2) + 1;
	return result;
}

double Quad(double x)
{
	return (x * x) + 5;
}

int main(void)
{
	printf("%f\n", precision);

	double num = 32;

	// linear test
	double testN = Linear(num); 
	double testD = Derivative(Linear, num);

	printf("linear test of %f with F(): %f and F`(): %f\n\n", 
			num, testN, testD);

	// quad test
	double testNq = Quad(num); 
	double testDq = Derivative(Quad, num);

	printf("linear test of %f with F(): %f and F`(): %f\n\n",
			num, testNq, testDq);

	// sqrt test
	double testNs = sqrt(num); 
	double testDs = Derivative(sqrt, num);

	printf("linear test of %f with F(): %f and F`(): %f\n\n",
			num, testNs, testDs);

	return 0;
}