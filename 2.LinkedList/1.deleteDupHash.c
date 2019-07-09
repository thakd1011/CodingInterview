#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 100

typedef struct _NODE{
	int data;
	struct _NODE* next;
}Node;

Node* makeNode(int data);
int makeHashCode(int key);
void insertHashData(Node* hashTable[], int hashKey, int hashValue);

Node* makeNode(int newData) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = newData;
	newNode->next = NULL;

	return newNode;
}

int makeHashCode(int key) {
	return key % HASHSIZE;
}

void insertHashData(Node* hashTable[], int hashKey, int hashValue) {
	int hashIndex = makeHashCode(hashKey);

	if(hashTable[hashIndex]->next == NULL) {
		hashTable[hashIndex]->data = hashValue;
	}
}

int main() {

	Node* hashTable[HASHSIZE];
	Node* head = (Node*)malloc(sizeof(Node));
	Node* current = head;

	int randomKey, randomValue;
	for(int i=0; i<HASHSIZE; i++) {
		hashTable[i] = (Node*)malloc(sizeof(Node));
	}

	for(int i=0; i<30; i++) {
		randomKey = rand() % 20 + 1;
		randomValue = randomKey;

		Node* nextNode = makeNode(randomKey);

		current->next = nextNode;
		current = current->next;
	}
	
	current = head;

	while(current->next != NULL) {
		printf("temp = %d\n",current->data);
		insertHashData(hashTable, current->data, current->data);
		current = current->next;
	}
	
	for(int i=0; i<HASHSIZE; i++) {
		printf("%d\t", hashTable[i]->data);
	}
}
