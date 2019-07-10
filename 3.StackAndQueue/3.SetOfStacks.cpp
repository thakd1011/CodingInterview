#include <stdio.h>
#include <stack>
#include <vector>

#define FULLSIZE 10

using namespace std;

// set of stacks like one stack!
vector < stack<int> > s;
int stackIndex = 0;

int isFull() {
	if(s[stackIndex].size() == FULLSIZE) return 1;
	else 0;
}

int main() {
	
	int selectionNum = 1;
	int pushNum = 0;
	int tempTop;

	s.push_back(stack<int> s);
	printf("\n%d\n\n", s[stackIndex].empty());
	
	do {
		printf("<select one>\n1.push\n2.pop\n0.Quit\n======================\n\n");
		scanf("%d", &selectionNum);

		switch(selectionNum) {
			case 1:
				printf("push number you want\n");
				scanf("%d",&pushNum);
				
				if(isFull()) {
					stackIndex++;
				}

				s[stackIndex].push(pushNum);	
				break;
			
			case 2:
				if(s[stackIndex].empty()) {
					stackIndex -= 1;
					if(stackIndex >= 0 && s[stackIndex].empty()) {
						printf("All stacks is empty!\n");
					}
					else {
						tempTop = s[stackIndex].top();
						s[stackIndex].pop();
						printf("pop %d", tempTop);
					}
				}
				else {
					tempTop = s[stackIndex].top();
					s[stackIndex].pop();
					printf("pop %d", tempTop);
				}

				break;
		}
	}while(selectionNum != 0);
}

