// A simple c linked list program

#include <stdio.h>
#include <stdlib.h>

// Basic node
struct Node {
	int data;
	struct Node* next;
};

void printList(struct Node* n)
{
	while (n != NULL)
	{
		printf("%d\n", n->data);
		n = n->next;
	}
}

int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// the vars now hold the pointers to these allocations
	head = (struct Node*) malloc(sizeof(struct Node));
	second = (struct Node*) malloc(sizeof(struct Node));
	third = (struct Node*) malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;
	//assign the data for head and assign its pointer to second

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
	// assign the last pinter to nothing

	printList(head);

	return 0;
}