/*
   문제 6. 하노이타워
   전형적인 하노이타워에서는 크기가 서로 다른 N개의 원판을 세 개의 기둥 중 아무 곳으로나 옮길 수 있다.
   초기에 원반은 크기가 맨 위에서부터 아래로 커지는 순서대로 쌓여있다.
   그리고 이 문제에는 다음과 같은 제약조건이 있다.
   1) 원반을 한 번에 하나만 옮길 수 있다.
   2) 맨 위에 있는원반 하나를 다른 기둥으로 옮길 수 있다.
   3) 원반은 자신보다 크기가 작은 디스크 위에 놓을 수 없다.

   스택을 사용하여 모든 원반을 첫 번재 기둥에서 마지막 기둥으로 옮기는 프로그램을 작성하라
 */
#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

const void diskMove(int n, int from, int mid, int to) {
	cout << "disk " << n << " move from " << from << " to " << to << "\n";
}

const void stack_hanoi(int n, int from, int mid, int to) {
	int flag = 1;

	do{
		while(n > 1) {
			s.push(to);
			s.push(mid);
			s.push(from);
			s.push(n);
			n--;
			s.push(to);
			to = mid;
			mid = s.top();
			s.pop();
		}
		
		diskMove(n, from, mid, to);

		if(!s.empty()) {
			n = s.top();
			s.pop();
			from = s.top();
			s.pop();
			mid = s.top();
			s.pop();
			to = s.top();
			s.pop();
			
			diskMove(n, from, mid, to);

			n--;
			s.push(from);
			from = mid;
			mid = s.top();
			s.pop();
		}
		else {
			flag = 0;
		}
	}while(flag == 1);
}

// recursive
const void reHanoiTower(int n, int from, int mid, int to) {
	if(n == 1) {
		cout << "disk 1 from " << from << " to " << to << "\n";
		return;
	}
	else {
		reHanoiTower(n - 1, from, to, mid);
		cout << "disk " << n << " from " << from << " to " << to << "\n";
		reHanoiTower(n - 1, mid, from, to);
	}
}

using namespace std;

int main() {
	int N;
	cout << "input disk num\n";
	cin >> N;

	// recursive
	reHanoiTower(N, 1, 2, 3);

	// using three stacks
	cout << "\n\n======stack hanoi=====\n";
	stack_hanoi(N, 1, 2, 3);
}
