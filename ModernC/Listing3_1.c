#include <stdlib.h>
#include <stdio.h>

/* iteration limits around one */
static long double const eps1m01 = 1.0 - 0x1P-01;
static long double const eps1p01 = 1.0 + 0x1P-01;
static long double const eps1m24 = 1.0 - 0x1P-24;
static long double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[argc+1])
{	
	long double test = 1.0;
	printf("%Lf\n", eps1m24);
	for (int i = 1; i < argc; ++i) // go through all arguments
	{
		long double const a = strtod(argv[i], 0); // grab the float value in the arg
		long double x = 1.0; // number

		// set the value of x to be the
		// the multiplier to get a between 0.5 and 1.5
		for (;;)
		{
			long double prod = a * x;
			printf("Value prod during loop: %Lf\n", prod);
			if (prod < eps1m01)
			{
				x *= 2.0;
			} else if (eps1p01 < prod)
			{
				x *= 0.5;
			} else
			{
				break;
			}
			printf("Value x during loop: %Lf\n", x);
		}

		printf("Value x before aproximation: %Lf\n", x);
		// heron aproximation
		for (;;) 
		{
			long double prod = a * x;
			printf("Value prod during aproximation: %Lf\n", prod);
			if ((prod > eps1m24) || (eps1p24 < prod))
			{
				x *= (2.0 - prod);
			} else
			{
				break;
			}
			printf("Value x during aproximation: %Lf\n", x);
		}
		printf("Value x final: %Lf\n", x);
		printf("heron: a=%.5Le,\tx=%.5Le,\ta*x=%Lf\n",
				a, x, a*x);
	}
	return EXIT_SUCCESS;
}