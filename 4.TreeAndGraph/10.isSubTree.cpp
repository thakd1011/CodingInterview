// make minimum depth tree
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct _NODE {
	int data;
	struct _NODE* left;
	struct _NODE* right;
}node;

node* makeNode(int newData) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

node* makeTree(int start, int end, int* treeArray) {
	if(start <= end)	{
		int mid = (start + end) / 2;
		int data = treeArray[mid];

		node* root = makeNode(data);
		
		root->left = makeTree(start, mid - 1, treeArray);
		root->right = makeTree(mid + 1, end, treeArray);
		
		return root;
	}
	else {
		return NULL;
	}
}

bool isMatch(node* T1, node* T2) {
	// caution!
	if(T1 == NULL && T2 == NULL) {
		return true;
	}
	else if(T1 == NULL || T2 == NULL) {
		return false;
	}
	else {
		if(isMatch(T1->left, T2->left) && isMatch(T1->right, T2->right)) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool isSubTree(node* T1, node* T2) {
	if(T2 == NULL) return true;
	if(T1 == NULL) return false;

	if(T1->data == T2->data) {
		if(isMatch(T1, T2)) {
			return true;
		}
	}
	return isSubTree(T1->left, T2) || isSubTree(T1->right, T2);
}

int main(const int argc, const char* argv[]) {
	
	if(argc < 2) {
		printf("more input plz\n");
		exit(1);
	}

	int length = argc;
	int secondLength = 4;
	int* treeArray = (int*)malloc(sizeof(int) * length);
	int* T2Arr = (int*)malloc(sizeof(int) * secondLength);

	// init second tree - T2 (custom..)
	for(int i=0; i<secondLength; i++) {
		T2Arr[i] = i + 3;
	}

	for(int i=1; i<argc; i++) {
		treeArray[i - 1] = atoi(argv[i]);
	}
	
	node* T1 = makeTree(0, length - 2, treeArray);
	node* T2 = makeTree(0, secondLength - 1, T2Arr);

	if(isSubTree(T1, T2)) {
		cout << "T2 is T1's SubTree!\n";
	}
	else {
		cout << "T2 isn't T1's subtree\n";
	}

}
