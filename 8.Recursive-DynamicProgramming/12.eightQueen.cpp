/*
   문제 12. 여덟 개의 퀸
   8x8 체스판 위에 여덟 개의 퀸이 서로 잡아 먹히지 않도록 놓을 수 있는
   모든 가능한 방법을 출력하는 알고리즘을 작성하라.
   즉, 퀸은 서로 같은 행, 열, 대각선 상에 놓이면 안 된다.
   여기서 대각선은 모든 대각선을 의미하는 것으로
   체스판을 양분하는 대각선 두 개로 한정하지 않는다.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#define BOARDSIZE 8

int rows[BOARDSIZE]; // row[i] = j: i번째 row의 j column에 퀸 저장되어있음.
int cnt;

bool canPutQueen(int row, int col) {
	for(int i = 0; i < row; i++) {
		int tempCol = rows[i];
		int rowDiff = row - i;
		int colDiff = abs(col - tempCol);
		if(tempCol == col) {
			return false;
		}
		if(colDiff == rowDiff) {
			return false;
		}
	}
	return true;
}

void putQueen(int row) {
	if(row == BOARDSIZE) {
		// last recursive call
		cnt++;
		return;
	}

	for(int i = 0; i < BOARDSIZE; i++) {
		if(canPutQueen(row, i)) {
			rows[row] = i;
			putQueen(row + 1);
		}
	}
}

int main() {
	for(int i = 0; i < BOARDSIZE; i++) {
		rows[i] = -1;
	}
	putQueen(0);
	cout << "queen's cnt = " << cnt <<"\n";
}
