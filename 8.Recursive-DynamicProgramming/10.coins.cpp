/*
   문제 11.
   쿼터(25센트), 다임(10센트), 니켈(5센트), 페니(1센트)의 네 가지 동전이 무한히 주어졌을때
   n센트를 표현하는 모든 방법의 수를 계산하는 코드를 작성하라.
   11 -> 13가지?

 */

#include <iostream>
#include <vector>

using namespace std;

// recursive

int coin[4] = {25, 10, 5, 1};

int re_nCent(int money, int idx) {
	int caseCnt = 0;

	if(money < 0) {
		return 0;
	}
	else if(money == 0) {
		return 1;
	}
	else {
		for(int i = idx; i < 4; i++) {
			int cnt = money / coin[i];
			for(int j = 1; j <= cnt; j++) {
				caseCnt += re_nCent(money - coin[i] * j, i + 1);
			}
		}
	}

	return caseCnt;
}

int main() {
	int N, cnt;

	cout << "input N cent\n";
	cin >> N;

	cnt = re_nCent(N, 0);
	cout << "res = " << cnt<<"\n";
}
