#include <stdio.h>
#include <stdlib.h>

// TODO : how to count loop size K?
// pointer is collision where far from loop start point 'K';
typedef struct _NODE {
	int data;
	struct _NODE* next;
}node;

node* makeNode(int newData) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->next = NULL;

	return newNode;
}

int isCollision(node* first, node* second) {
	if(&first->data == &second->data) return 1;
	else return 0;
}

node* startPoint(node* head) {
	node* first = head->next;
	node* second = head->next;

	do{
		first = first->next;
		second = second->next->next;
		printf("first = %d, second = %d\n", first->data, second->data);

	}while(!isCollision(first, second));
	return first;
}

int main() {
	// hard coding for test..... TT
	node* head = (node*)malloc(sizeof(node));
	node* current = head;
	node* startLoop = head;
	node* collisionPoint;

	current->next = makeNode(1);
	current = current->next;
	startLoop = current;

	current->next = makeNode(2);
	current = current->next;
	startLoop = current;

	current->next = makeNode(3);
	current = current->next;
	startLoop = current;

	current->next = makeNode(4);
	current = current->next;
	startLoop = current;

	current->next = makeNode(5);
	current = current->next;

	current->next = makeNode(6);
	current = current->next;

	current->next = makeNode(7);
	current = current->next;

	current->next = makeNode(8);
	current = current->next;

	current->next = startLoop;
	
	collisionPoint = startPoint(head);
	printf("loop start point's data = %d\n", collisionPoint->data);
	
	current = head->next;
	for(int i=0; i<15; i++) {
		printf("node's data = %d, address = %p\n", current->data, &current->data);
		current = current->next;
	}
}
