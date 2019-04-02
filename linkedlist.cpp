// Program to delete last occurrence of an item from linked list

#include <iostream.h> 

struct Node { 
	int key; 
	struct Node* next; 
}; 

void deleteLast(Node* head, int key) 
{ 
	Node* x = NULL; 

	Node* temp = head; 
	while (temp) { 
		if (temp->key == key) 
			x = temp; 

		temp = temp->next; 
	} 

	if (x != NULL) { 

		x->key = x->next->key; 

		temp = x->next; 
		x->next = x->next->next; 

		delete temp; 
	} 
} 

Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 

void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		printf(" %d ", node->key); 
		node = node->next; 
	} 
} 

int main() 
{ 
	struct Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(5); 
	head->next->next->next->next = newNode(2); 
	head->next->next->next->next->next = newNode(10); 

	puts("Created Linked List: "); 
	printList(head); 
	deleteLast(head, 2); 
	puts("\nLinked List after Deletion of 1: "); 
	printList(head); 
	return 0; 
} 
