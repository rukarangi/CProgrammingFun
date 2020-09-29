#include <stdlib.h>
#include <stdio.h>

// fill a list ascending to size N
void InitialiseTable(size_t N, size_t parent[N])
{
	for (size_t i = 0; i < N; ++i)
	{
		parent[i] = i;
	}
}

// print table with new lines every five elements
void Print(size_t N, size_t parent[N])
{
	for (size_t i = 0; i < N; ++i)
	{
		printf("%zu  ", parent[i]);
		if (((i + 1) % 5) == 0)
		{
			printf("\n\n");
		}
	}
}



#define TABLE_SIZE 10

int main(void)
{
	size_t parent[TABLE_SIZE];
	InitialiseTable(TABLE_SIZE, parent);
	Print(TABLE_SIZE, parent);


	return 0;
}