// check Linked List is it palindrome?
// using fast runner pointer!
#include <stdio.h>
#include <stdlib.h>

int semiStack[100];
int top = -1;

typedef struct _NODE{
	int data;
	struct _NODE* next;
}node;

node* makeNode(int newData) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->next = NULL;

	return newNode;
}

node* changeNodeMiddleAddr(node* listHead, node* first, node* second) {
	while(first != NULL) {
		
		if(first->next != NULL) {
			semiStack[++top] = second->data;
			
			if(first->next->next == NULL) {
				return second;
			}
			else {
				first = first->next->next;
				second = second->next;
			}
		}
		else {
			return second;
		}
	}
	
	return second;
}

int isPalindrome(node* first, node* second) {
	while(second->next != NULL) {

		if(semiStack[top] != second->next->data) {
			return 0;
		}
		
		top--;

		second = second->next;
		first = first->next;
	}
	return 1;
}

int main(const int argc, char* argv[]) {
	if(argc < 2) {
		fprintf(stderr, "usage err in main\n");
		exit(1);
	}
	
	node* listHead = (node*)malloc(sizeof(node));
	node* current = listHead;
	node* first;
	node* second;

	
	for(int i=1; i<argc; i++) {
		current->next = makeNode(atoi(argv[i]));
		current = current->next;
	}

	first = second = listHead->next;
	second = changeNodeMiddleAddr(listHead, first, second);

	first = listHead;

	if(isPalindrome(first, second)) {
		printf("True\n");
	}
	else {
		printf("False\n");
	}
	// POINT : we check just half of list atom.
	// if the Linekd list is palindrome,
	// half of front lists equals half of end lists
}
