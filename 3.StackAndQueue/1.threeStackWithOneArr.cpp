// make three stack using only one array! -> how can I..?
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int STACK[300];
	int filled[3];
//0~99, 100~199, 200~299

bool isFull(int stackNum);
bool isEmpty(int stackNum);

int topIndex(int stackNum) {
	return MAXSIZE * stackNum + filled[stackNum] - 1;
}

bool isFull(int stackNum) {
	if(filled[stackNum] == MAXSIZE) {
		return true;
	}
	else {
		return false;
	}
}

bool isEmpty(int stackNum) {
	if(filled[stackNum] == 0) {
		return true;
	}
	else {
		return false;
	}
}


void push(int stackNum, int data) {
	if(isFull(stackNum)) {
		printf("stack is full!\n");
	}
	else {
		STACK[topIndex(stackNum) + 1] = data;
		filled[stackNum] += 1;
	}
}

int pop(int stackNum) {
	if(isEmpty(stackNum)) {
		printf("stack is empty!\n");
		return -1;
	}
	else {
		int data = STACK[topIndex(stackNum)];
		filled[stackNum] -= 1;
		return data;
	}
}


int main() {
	push(0, 1);
	push(0, 2);
	push(0, 3);
	push(0, 4);
	printf("back two = %d %d\n", pop(0), pop(0));


	for(int i=0; i<10; i++) {
		printf("stack1 = %d\n", pop(0) );
	}
}
