//search k-th node data of back
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

typedef struct _NODE{
	int data;
	struct _NODE* next;
}Node;

Node* kthNode;
int count;

Node* makeNode(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = NULL;

	return newNode;
}

void makeLinkedList(Node* listHead) {
	Node* temp = listHead;
	int randomNum;
	for(int i=0; i<MAXSIZE; i++) {
		randomNum = rand() % 40 + 1;
		Node* newNode = makeNode(randomNum);
		temp->next = newNode;
		temp = temp->next;
		printf("%d -> ", randomNum);
	}
}

void searchKthNode(Node* current, int k){

	if(current->next == NULL) {
		count++;
		return;
	}
	else {
		searchKthNode(current->next, k);
		count++;
	}

	if(count == k) {
		kthNode = current;
	}
}


int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	makeLinkedList(head);
	
	searchKthNode(head, 2);

	printf("\nresult = %d\n", kthNode->data);
}
