#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

stack<int> s1, s2;

int main() {
	int switchNum, num = 0, stackNum = 1, data = 0, beforeCmd = 0;

	do {
		printf("0:quit\n1:push\n2:pop\n");
		scanf("%d", &switchNum);

		// TODO : SWITCH loop refactorying!
		switch(switchNum) {
			case 0 :
				break;

			case 1 :// push back
				printf("push num : \n");
				scanf("%d", &num);
				if(beforeCmd == 1) {
					if(stackNum == 1) {
						s1.push(num);
					}
					else {
						s2.push(num);
					}
				}
				else {
					if(stackNum == 1) {
						while(!s1.empty()) {
							data = s1.top();
							s1.pop();
							s2.push(data);
						}
						s2.push(num);
						stackNum = 2;
					}
					else {
						// TODO: stack empty Exception!
						while(!s2.empty()) {
							data = s2.top();
							s2.pop();
							s1.push(data);
						}
						s1.push(num);
						stackNum = 1;
					}
				}
				break;

			case 2 : // pop front
				if(beforeCmd == 2) {
					if(stackNum == 1) {
						printf("pop front = %d\n", s1.top());
						s1.pop();
					}
					else {
						printf("pop front = %d\n", s2.top());
						s2.pop();
					}
				}
				else {
					if(stackNum == 1) {
						while(!s1.empty()) {
							data = s1.top();
							s1.pop();
							s2.push(data);
						}
						printf("pop front = %d\n",s2.top() );
						s2.pop();
						stackNum = 2;
					}
					else {
						while(!s2.empty()) {
							data = s2.top();
							s2.pop();
							s1.push(data);
						}
						printf("pop front = %d\n", s1.top());
						s1.pop();
						stackNum = 1;
					}
				}
				break;
		}
		beforeCmd = switchNum;

	}while(switchNum != 0);
}
