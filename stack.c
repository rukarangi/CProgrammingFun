// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Struct for node in stack
struct StackNode
{
	int data; // Actual data stored in each node in stack
	struct StackNode* next; // Pointer to the next item in the stack
};

struct StackNode* newNode(int data) 
// Create a new node and take data to put in ti
{
	struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(struct StackNode));
	// Create a pointer to a new allocation of memory for one node

	stackNode->data = data; 
	// Add data to new allocation
	stackNode->next = NULL; 
	// Add null to pointer, cause no next node
	return stackNode;
};

int isEmpty(struct StackNode *root) 
// Take pointer to the root node of the linked list
{
	return !root; 
	// If the root node contains not value return True if it does contain pointer return False
};

void push(struct StackNode** root, int data)
{
	struct StackNode* stackNode = newNode(data); 
	// Create the new newnode to be added

	stackNode->next = *root;
	*root = stackNode;
	/*
	This part^^ Hard to get
	first we grab the last node that root had and pass it to the next
	then we give root the new last node 
	which is the stacknode we just made
	*/
	printf("%d pushed to stack\n", data);
	// Print results
};

int pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	// Just check if root is pointing to anything
	struct StackNode* temp = *root;
	// Get the current top node
	*root = (*root)->next;
	// Root now points to whatever it was holding as next
	int popped = temp->data;
	// Grab the data held at the node that was just popped
	free(temp);
	// Free the memory allcated when creatin the node

	return popped;
	// Return the top value for use
};

int peek(struct StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
	// Just return the value of the top node
}

// Main
int main()
{
	struct StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	printf("%d popped from stack\n", pop(&root));

	printf("Top element in %d\n", peek(root));
};