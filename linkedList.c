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
		printf("\n%d\n", n->data);
		n = n->next;
	}
}

void push(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = (*headRef);
	(*headRef) = newNode;
	/*
	We pass a double pointer into this so that we can modify
	the orignal head pointer ouside of this funcs
	scope.
	*/
}

void insertAfter(struct Node* prev, int data)
{
	if (prev == NULL)
	{
		printf("the given previous node cannot be NULL\n");
		return;
	}
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;

	newNode->next = prev->next;
	prev->next = newNode;
}

void append(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = data;

	struct Node *last =  *headRef;

	newNode->next = NULL;

	if (*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = newNode;
	return;
}

int main()
{	
	struct Node* head = NULL;

	append(&head, 6);

	push(&head, 7);

	push(&head, 1);

	append(&head, 4);

	insertAfter(head->next, 8);

	printf("\nCreated linked list is:");
	printList(head);

	/*struct Node* head = NULL;
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

	printList(head);*/

	return 0;
}