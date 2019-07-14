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

// pre-ordering
void printAllTree(node* root) {
	if(root != NULL) {
		cout << root->data << "\t";
		printAllTree(root->left);
		printAllTree(root->right);
	}
}

int main(const int argc, const char* argv[]) {
	
	if(argc < 2) {
		printf("more input plz\n");
		exit(1);
	}

	int length = argc;
	int* treeArray = (int*)malloc(sizeof(int) * length);

	for(int i=1; i<argc; i++) {
		treeArray[i - 1] = atoi(argv[i]);
	}
	
	node* root = makeTree(0, length - 2, treeArray);

	printAllTree(root);
}
