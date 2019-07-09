#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int listToNum(node* pointer, int digits) {
	if(pointer->next == NULL) {
		return pointer->data * pow(10, digits);
	}
	else {
		return pointer->data * pow(10, digits) + listToNum(pointer->next, digits + 1);
	}
}

int main(const int argc, char* argv[]) {
	if(argc < 2) {
		fprintf(stderr, "usage: main \n");
		exit(1);
	}
	
	node* firstHead = (node*)malloc(sizeof(node));
	node* secondHead = (node*)malloc(sizeof(node));
	node* resultHead = (node*)malloc(sizeof(node));
	node* current = firstHead;

	int left = 0, right = 0, result = 0;
	char* compareString = "+";

	for(int i=1; i<argc; i++) {
		if(strcmp(argv[i], compareString)==0) {
			current = secondHead;
		}
		else {
			for(int j=0; argv[i][j]!='\0'; j++) {
				
				if(current->next == NULL) {
					current->next = makeNode(argv[i][j] - '0');
				}
				else {
					node* nextNode = current->next;
					current->next = makeNode(argv[i][j] - '0');
					current->next->next = nextNode;
				}
			}
		}
	}

	left = listToNum(firstHead->next, 0);
	right = listToNum(secondHead->next, 0);
	result = left + right;

	current = resultHead;

	while(result != 0) {
		if(current->next == NULL) {
			current->next = makeNode(result % 10);
		}
		else {
			node* nextNode = current->next;
			current->next = makeNode(result % 10);
			current->next->next = nextNode;
		}
		result /= 10;
	}
	
	while(resultHead->next != NULL) {
		printf("%d->", resultHead->next->data);
		resultHead = resultHead->next;
	}
	//printf("left = %d, right = %d\n", left, right);
}
