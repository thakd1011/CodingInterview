#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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

node* partition(node* listHead, int X) {
	node* leftList = (node*)malloc(sizeof(node));
	node* rightList = (node*)malloc(sizeof(node));
	node* pointerL = leftList;
	node* pointerR = rightList;

	while(listHead->next != NULL) {
		int value = listHead->next->data;
		if(value < X) {
			pointerL->next = makeNode(value);
			pointerL = pointerL->next;
		}
		else {
			pointerR->next = makeNode(value);
			pointerR = pointerR->next;
		}

		listHead = listHead->next;
	}
	
	// merge left/right and delete right head
	pointerL->next = rightList->next;
	
	return leftList;
}

int main(const int argc, const char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "usage: main X [INT, [INT, ...]]\n");
		exit(1);
	}

	const int X = atoi(argv[1]);
	
	node* head = (node*)malloc(sizeof(node));
	node* current = head;
	node* partitionedHead = (node*)malloc(sizeof(node));

	for(int i=2; i<argc; i++) {
		node* temp = makeNode(atoi(argv[i]));

		current->next = temp;
		current = current->next;
	}
	
	partitionedHead = partition(head, X);

	// left list < X
	while(partitionedHead->next != NULL) {
		printf("%d -> ", partitionedHead->next->data);
		partitionedHead = partitionedHead->next;
	}
	printf("\n\n");
}
