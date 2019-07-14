#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define INF 987654321

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

node* makeTree(int start, int end, int* treeArray){
	if(start > end) return NULL;

	int mid = (start + end) / 2;
	int data = treeArray[mid];

	node* root = makeNode(data);

	root->left = makeTree(start, mid - 1, treeArray);
	root->right = makeTree(mid + 1, end, treeArray);

	return root;
}

bool isBinary(node* root, int max, int min) {
	if(root == NULL) return true;

	int tempData = root->data;
	if(tempData < min || tempData > max) return false;

	bool left = isBinary(root->left, tempData, min);
	bool right = isBinary(root->right, max, tempData);
	
	if(left == false || right == false) return false;

	return true;
}

int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout << "more input plz\n";
		exit(1);
	}

	int length = argc - 1;
	int* treeArray = (int*)malloc(sizeof(int) * length);
	bool result = false;

	for(int i=0; i<length; i++) {
		treeArray[i] = atoi(argv[i + 1]);
	}

	node* root = makeTree(0, length - 1, treeArray);
	
	result = isBinary(root, INF, -INF);

	if(result == true) cout <<"true"<<"\n";
	else cout <<"false"<<"\n";
}
