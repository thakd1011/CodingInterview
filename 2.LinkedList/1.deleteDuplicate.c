#include <stdio.h>
#include <stdlib.h>
// given not sorted list, remove duplicated atom in linkedlist.

typedef struct NODE{
	int data;
	struct NODE* next;
}Node;

Node* makeNode(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = NULL;

	return newNode;
}

void printAllData(Node* listHead) {
	for(Node* n = listHead->next; n != NULL; n = n->next){
		printf("%d\t", n->data);
	}
	printf("\n");
}

void insertRandom(Node* listHead, int count)  {
	int randomData = 0;
	Node* current = listHead;

	for(int i=0; i<count; i++) {
		randomData = rand() % 10 + 1;
		current->next = makeNode(randomData);
		current = current->next;
	}
}

// O(n^2) for remove....
void removeDuplicate(Node* listHead) {
	for(Node* newNode = listHead->next; newNode != NULL; newNode = newNode->next) {
		for(Node* cmpNode = newNode; cmpNode != NULL; cmpNode = cmpNode->next) {
			Node* cmpNextNode = cmpNode->next;

			if((cmpNextNode != NULL) && (cmpNextNode->data == newNode->data)){
				cmpNode->next = cmpNextNode->next;
				free(cmpNextNode);
			}
		}
	}
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;

	insertRandom(head, 25);
	printAllData(head);

	removeDuplicate(head);
	printf("<after>");
	printAllData(head);
}
