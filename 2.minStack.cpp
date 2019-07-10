#include <stdio.h>
#include <stack>

using namespace std;
// O(1) time - min function in stack

int main() {
	stack<int> originStack;
	stack<int> minStack;

	int selectionNum = 1;
	int pushNum = 0;
	int tempTop;

	do {
		printf("<select one>\n1.push\n2.pop\n3.min of stack\n0.Quit\n======================\n\n");
		scanf("%d", &selectionNum);

		switch(selectionNum) {
			case 1:
				printf("push number you want\n");
				scanf("%d",&pushNum);

				originStack.push(pushNum);

				if(minStack.empty()) {
					minStack.push(pushNum);
				}
				else {
					tempTop = minStack.top();
					tempTop > pushNum ? minStack.push(pushNum) : minStack.push(tempTop);
				}
				break;

			case 2:
				if(originStack.empty()) {
					break;
				}
				tempTop = originStack.top();
				printf("pop data = %d\n", tempTop);
				originStack.pop();
				minStack.pop();
				break;

			case 3:
				if(minStack.empty()) {
					printf("empty stack\n");
					break;
				}
				int minTop = minStack.top();
				printf("min in stack = %d\n", minTop);
				break;

		}
	}while(selectionNum != 0);
}
