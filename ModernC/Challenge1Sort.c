/*#include <stdlib.h>
#include <stdio.h>

void CopyArray(double A[], size_t begin, size_t end, double B[])
{
	for (size_t i = begin; begin < end; ++i)
	{
		B[i] = A[i];
	}
}

/* left is A[begin:middle]
 * right is A[middle:end]
 * result is B[begin:end]
 *
void TopDownMerge(double B[], size_t begin, size_t middle, size_t end, double A[])
{
	size_t b = begin;
	size_t m = middle;

	for (size_t i = begin; i<end; ++i)
	{
		if(b < middle && (m >= end || A[b] <= A[m]))
		{
			B[i] = A[m];
            b = b + 1;
		} else
		{
			B[i] = A[b];
            m = m + 1;
		}
	}
}

void TopDownSplitMerge(double B[], size_t begin, size_t end, double A[])
{
	// case if we have reach bottom level
	if((begin - end) <= 1)
		return; 

	// get middle position
	size_t middle = (begin + end) / 2;

	TopDownSplitMerge(A, begin, middle, B); // sort the left partition
	TopDownSplitMerge(A, middle, end, B); // sort the right partition

	// merge B onto A
	TopDownMerge(B, begin, middle, end, A);

}

void TopDownMergeSort(double A[], double B[], size_t n)
{
	// copy values of A in B
	CopyArray(A, 0, n, B);
	// using B sort into A
	TopDownSplitMerge(B, 0, n, A);
}

// array length
//size_t const LENGTH = 19; 
static size_t const ARR_SIZE = 19;

int main(int argc, char* argv[argc+1])
{
	/* code *

	double A[19] = {
		[0] = 8.0,
		[1] = 0.1,
		[2] = 5.8,
		[3] = 34.6,
		[4] = 5.9,
		[5] = 7.0,
		[6] = 3.1,
		[7] = 2.8,
		[8] = 54.6,
		[9] = 6.8,
		[10] = 4.0,
		[11] = 2.1,
		[12] = 1.8,
		[13] = 9.6,
		[14] = 7.8,
		[15] = 5.0,
		[16] = 3.1,
		[17] = 2.8,
		[18] = 4.6,
	};
	double B[19];

	TopDownMergeSort(A, B, 19);

	for (size_t i = 0; i < 19; ++i)
	{
		printf("Array A at: %ld is: %f\n",i , A[i]);
	}

	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

void TopDownMerge(size_t N, double A[N], size_t begin, size_t middle, size_t end, double B[N])
{   
    size_t b = begin, m = middle;

    for (size_t i = b; i < end; ++i)
    {
        if(b < middle && (m >= end || A[b] <= A[m]))
        {
            B[i] = A[b];
            ++b;
        } else
        {
            B[i] = A[m];
            ++m;
        }
    }

    return;
}

void TopDownSplitMerge(size_t N, double B[N], size_t begin, size_t end, double A[N])
{
    if(end < begin || end - begin < 2)
        return;

    size_t middle = begin + (end - begin) / 2;

    TopDownSplitMerge(N, A, begin, middle, B);
    TopDownSplitMerge(N, A, middle, end, B);

    TopDownMerge(N, B, begin, middle, end, A);
}

void CopyArray(size_t N, double A[N], size_t begin, size_t end, double B[N])
{
    for(size_t i = begin; i < end; ++i)
    {
        B[i] = A[i];
    }
}

void TopDownMergeSort(size_t N, double A[N], double B[N])
{
    CopyArray(N, A, 0, N, B);
    TopDownSplitMerge(N, B, 0, N, A);
}

#define ARR_SIZE 20

int main(void) 
{
    double B[ARR_SIZE];
    double A[ARR_SIZE] = {
        [0] = 1.1,
        [1] = 2.2,
        [2] = 3.3,
        [3] = 4.4,
        [4] = 5.5,
        [5] = 1.2,
        [6] = 2.3,
        [7] = 3.4,
        [8] = 4.5,
        [9] = 5.6,
        [10] = 1.7,
        [11] = 2.8,
        [12] = 3.9,
        [13] = 4.10,
        [14] = 5.11,
        [15] = 1.12,
        [16] = 2.14,
        [17] = 3.15,
        [18] = 4.16,
        [19] = 5.18,
    };

    TopDownMergeSort(ARR_SIZE, A, B);

    for (size_t i = 0; i < ARR_SIZE; ++i)
    {
        printf("at place: %zu, %f\n", i, A[i]);
    }
    
    return 0;
}