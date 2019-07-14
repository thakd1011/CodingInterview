#include <iostream>
#include <vector>
#include <math.h>

#define MAXSIZE 100

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
	if(start > end) return NULL;
	
	int mid = (start + end) / 2;
	int data = treeArray[mid];

	node* root = makeNode(data);

	root->left = makeTree(start, mid - 1, treeArray);
	root->right = makeTree(mid + 1, end, treeArray);

	return root;
}

void makeLinkedList(int depth, vector< vector<int> > &sameDepth, node* root) {
	if(root != NULL) {
		sameDepth[depth].push_back(root->data);

		makeLinkedList(depth + 1, sameDepth, root->left);
		makeLinkedList(depth + 1, sameDepth, root->right);
	}
}

int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout << "more input plz\n";
		exit(1);
	}

	int length = argc;
	int* treeArray = (int*)malloc(sizeof(int)*length);
	int depthMax = (log(length - 1) / log(2)) + 1;

	vector < vector <int> > sameDepth(depthMax);

	for(int i = 1; i < argc; i++) {
		treeArray[i - 1] = atoi(argv[i]);
	}

	node* root = makeTree(0, length - 2, treeArray);
	
	makeLinkedList(0, sameDepth, root);
	
	for(int i=0; i<depthMax; i++) {
		for(int j = 0; j < sameDepth[i].size(); j++){
			cout <<"data = " << sameDepth[i][j] <<"\t";
		}
		cout << "\n";
	}
}
