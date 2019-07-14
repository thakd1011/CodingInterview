// search all path satisfying the condition(successive node's sum == target sum)
// input : essence (negative, positive, zero)
// result : total path count
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

// brute force - O(N*logN), N : total node count
int containRootSum(node* root, int tempSum, int targetSum) {
	if(root == NULL) return 0;

	int tempValue = tempSum + root->data;
	int pathCount = 0;
	
	if(tempValue == targetSum) {
		pathCount++;
	}
	
	pathCount += containRootSum(root->left, tempValue, targetSum);
	pathCount += containRootSum(root->right, tempValue, targetSum);

	return pathCount;
}

int startSumPath(node* root, int targetSum) {
	if(root == NULL) return 0;
	
	int tempPath = containRootSum(root, 0, targetSum);

	int leftPath = startSumPath(root->left, targetSum);
	int rightPath = startSumPath(root->right, targetSum);

	return tempPath + leftPath + rightPath;
}

int main(const int argc, const char* argv[]) {
	
	if(argc < 2) {
		printf("more input plz\n");
		exit(1);
	}

	int length = argc;
	int targetSum = 0;
	int result = 0;
	int* treeArray = (int*)malloc(sizeof(int) * length);

	for(int i=1; i<argc; i++) {
		treeArray[i - 1] = atoi(argv[i]);
	}
	
	node* root = makeTree(0, length - 2, treeArray);
	
	cout <<"input target sum";
	cin >> targetSum;

	result = startSumPath(root, targetSum);

	cout << "path count = " << result <<"\n";
}
