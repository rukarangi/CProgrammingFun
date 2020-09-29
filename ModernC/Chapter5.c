#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	// exs 13
	signed short min = -32768;
	signed short max = 32768; // roles over
	signed maxi = 32768;

	printf("%d\n", min);
	printf("%d\n", max);
	printf("%d\n", maxi);

	// exs 14
	signed short huh = 0x8000;

	printf("exercise 14 \n%d\n", (-0x8000));
	printf("%d\n", huh);

	// exs 15
	_Bool uBool = -1U;
	unsigned char uChar = -1UL;
	unsigned short uShort = -1ULL;

	printf("exercise 15 \n%d\n%d\n%d\n", uBool, uChar, uShort);

	return 0;
}