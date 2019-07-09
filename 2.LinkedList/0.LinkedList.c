#include <stdio.h>
#include <stdlib.h>

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

Node* searchKthNode(Node* listHead, int k) {
	int count = 0;
	Node* current = listHead;

	while(current->next != NULL && count < k) {
		Node* next = current->next;
		current = next;
		count++;
	}

	if(count == k) {
		return current;
	}
	else {
		return NULL;
	}
}

// insert data in front of List
void insertNode(Node* listHead, int inputData) {
	Node* insertNode = makeNode(inputData);
	if(listHead->next == NULL) {
		listHead->next = insertNode;
	}
	else {
		Node* headNext = listHead->next;
		listHead->next = insertNode;
		insertNode->next = headNext;
	}
}

// delete Kth node data
void deleteNode(Node* listHead, int k) {
	int prevNum = k - 1;
	Node* prevKthNode = searchKthNode(listHead, prevNum);

	if(prevKthNode->next != NULL) {
		Node* kthNode = prevKthNode->next;
		
		prevKthNode->next = kthNode->next;
		free(kthNode);
	}
	else {
		printf("Can't Delete!\n");
	}
}

void printAllData(Node* listHead) {
	Node* current = listHead;
	while(current->next != NULL) {
		printf("%d -> ",current->next->data);
		Node* next = current->next;
		current = next;
	}
	printf("NULL\n\n");
}

int main() {
	int insertData, deleteLocation, kNum, selectionNum;
	
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	
	do {
		printf("select number\n1.InsertData\n2.DeleteData\n3.Search k-th Node data\n4.Show all Data\nIf you want to quit program, input '-1'\n");
		scanf("%d",&selectionNum);

		switch(selectionNum) {
			case 1:
				printf("input new data : ");
				scanf("%d", &insertData);
				insertNode(head, insertData);
				break;
			case 2:
				printf("input number you want to delete location(1~N) : ");
				scanf("%d", &deleteLocation);
				deleteNode(head, deleteLocation);
				printf("Deleted last data\n");
				break;

			case 3:
				printf("input what you want to search k-th node data : ");
				scanf("%d", &kNum);
				Node* kthNode = searchKthNode(head, kNum);
				printf("kth Data = %d\n", kthNode->data);
				break;

			case 4:
				printf("<current data list>\n");
				printAllData(head);
				break;

		}
		printf("\n\n");
	}while(selectionNum != -1);
}
