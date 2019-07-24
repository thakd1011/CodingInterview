/*
   문제1.
   어떤 아이가 n개의 계단을 오른다. 한 번에 1 or 2 or 3계단을 오른다.
   계단을 오르는 방법이 몇 가지가 있는지 계산하는 메서드를 구현하라.
 */
#include <iostream>

using namespace std;

int main() {
	int* stair;
	int N;

	cout << "input stair N\n";
	cin >> N;

	stair = new int[N + 1];

	// base value
	stair[0] = 0;
	stair[1] = 1;
	stair[2] = 2;
	stair[3] = 4;

	for(int i = 4; i <= N; i++) {
		stair[i] = stair[i - 1] + stair[i - 2] + stair[i - 3];
	}
	
	cout << "jump to Nth stair count = " << stair[N] <<"\n";
	delete[] stair;
}
