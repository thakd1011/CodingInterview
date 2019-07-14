// search common ancestor node
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

// findNode function segmentation error! -> return value adjustment
node* findNode(node* root, int searchData) {
	cout << "temp root data = "<< root->data << ", want to search = "<<searchData <<"\n";
	if(root == NULL) return NULL;
	if(root->data == searchData) return root;
	else {
		node* leftRoot = findNode(root->left, searchData);
		node* rightRoot = findNode(root->right, searchData);

		if(leftRoot != NULL) return leftRoot;
		else if(rightRoot != NULL) return rightRoot;
		else return NULL;
	}
//	cout <<"\tleft = " << leftRoot <<", right = "<<rightRoot <<"\n";

}


bool isThere(node* root, int searchData) {
	if(root == NULL) return false;
	if(root->data == searchData) return true;
	
	return isThere(root->left, searchData) || isThere(root->right, searchData);
}

node* findCommonAncestor(node* root, node* p, node* q) {
	if(root == NULL) return NULL;

	if(root->data == p->data) {
		return p;
	}
	else if(root->data == q->data) {
		return q;
	}
	else if(isThere(root->left, p->data) && isThere(root->right, q->data)) {
		return findCommonAncestor(root->left, p, q);
	}
	else if(isThere(root->right, p->data) && isThere(root->right, q->data)) {
		return findCommonAncestor(root->right, p, q);
	}
	else {
		return root;
	}
}

int main(const int argc, const char* argv[]) {
	
	if(argc < 2) {
		printf("more input plz\n");
		exit(1);
	}

	int length = argc;
	int* treeArray = (int*)malloc(sizeof(int) * length);
	int p, q;

	for(int i=1; i<argc; i++) {
		treeArray[i - 1] = atoi(argv[i]);
	}

	// make Minimum depth Tree	
	node* root = makeTree(0, length - 2, treeArray);

	cout << "input two data\n";
	cin >> p >> q;
	
	node* first = findNode(root, p);
	node* second = findNode(root, q);

	node* ancestor = findCommonAncestor(root, first, second);

	if(ancestor != NULL) {
		cout << "ancestor node's data = " << ancestor->data << "\n";
	}
}
