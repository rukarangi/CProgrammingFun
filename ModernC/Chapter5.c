#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main(void)
{
	// exs 13
	signed short min = -32768;
	signed short max = 32768; // roles over
	signed maxi = 32768;

	/*printf("%d\n", min);
	printf("%d\n", max);
	printf("%d\n", maxi);*/
	
	// exs 14
	signed short huh = 0x8000;

	/*printf("exercise 14 \n%d\n", (-0x8000));
	printf("%d\n", huh);*/

	// exs 15
	_Bool uBool = -1U;
	unsigned char uChar = -1UL;
	unsigned short uShort = -1ULL;

	//printf("exercise 15 \n%d\n%d\n%d\n", uBool, uChar, uShort);

	// exs 22 - 27
	// bit wise operations

	unsigned short V = 0xFFFF; // = 65535 = 1111111111111111

	unsigned short A = 0x00F0; // = 240 = 0000000011110000
	unsigned short B = 0x011F; // = 287 = 0000000100011111

	/*
	V 			=	1111111111111111 = 65535 = 0xFFFF
	A 			= 	0000000011110000 = 240   = 0x00F0
	B       	=	0000000100011111 = 287   = 0x011F
	(A&B)   	= 	0000000000010000 = 16  	 = 0x0010 - AND
	A^B 		=	0000000111101111 = 495   = 0x01EF - XOR
	A|B 		= 	0000000111111111 = 511 	 = 0x01FF - OR
	~B 			=	1111111011100000 = 65248 = 0xFEE0 - NOT
	-B 			= 	1111111100000000 = 65289 = 0xFF00 - NEG

	A - (A&B)	=	0000000011100000 = 224 = 0x00E0 - A \ B Complement?
	B - (A&B)	=	0000000100001111 = 0x010F
	A + B 		=	0000001000001111 = 527 = 0x020F
	V - B 		= 	1111111011100000
	*/

	// 22 - preforming a complement on B from A - A \ B
	unsigned short bitOp = A - (A & B); // (A&B) = 0x0010 intersection

	printf("%hu\n", (bitOp));

	// 23 - show wrap with binary
	unsigned short newV = V + 1;

	printf("%hu\n", newV);

	// 24 - show that A XOR B = A \ B + B \ A
	unsigned short xORab = A ^ B;
	unsigned short xORComplements = (A - (A&B)) + (B - (A&B));

	printf("these two XORs are the same: %hu %hu\n", xORab, xORComplements);

	// 25 - show that A OR B = A + B - (A&B)
	unsigned short oRab = A | B;
	unsigned short oRaddMinusAND = A + B - (A&B);

	printf("these two ORs are the same: %hu %hu\n", oRab, oRaddMinusAND);

	// 26 - show that NOT B = V - B;
	unsigned short nOTb = ~B;
	unsigned short nOTvMinusb = V - B;

	printf("these two NOTs are the same: %hu %hu\n", nOTb, nOTvMinusb);

	// 27 - show that -B = ~B + 1;
	unsigned short nEGb = -B;
	unsigned short nEGnOTbPlus1 = ~B + 1;

	printf("these two NEGATIONSs are the same: %hu %hu\n", nEGb, nEGnOTbPlus1);

	// exs 28 - show that lost bits in x >> n = x % (1U << n)
	unsigned short x = 0x00F3; // = 243
	unsigned short n = 0x0002; // = 2

	/*
	1U 			=	0000000000000001 = 1 	= 0x0001
	x 			=	0000000011110011 = 243 	= 0x00F3
	n 			= 	0000000000000010 = 2	= 0x0002
	
	x << n 		= 	0000001111001100 = 972 	= 0x03CC
	x >> n 		= 	0000000000111100 = 60 	= 0x003C
	loss 		=	0000000000000011 = 3 	= 0x0003
	1U << n 	= 	0000000000000100 = 4	= 0x0004
	*/ 

	printf("%hu %hu %hu\n", 1U, x, n);

	unsigned short lEFT = x << n;

	printf("the left shift x of n: x << n = %hu << %hu = %hu \n", x, n, lEFT);

	unsigned short rIGHT = x >> n;
	unsigned short rIGHTloss = x % (1U << n);

	printf("the right shift x of n: x >> n = %hu >> %hu = %hu \n", x, n, rIGHT);
	printf("during the right shift, %hu, bits are lost\n", rIGHTloss);
	

	return 0;
}