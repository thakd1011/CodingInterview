/*
   문제 2.
   행의 개수는 r, 열의 개수는 c인 격자판의 왼쪽 상단 꼭짓점에 로봇이 놓여있다고 가정하자.
   이 로봇은 오른쪽 or 아래쪽으로만 이동할 수 있다.
   하지만 어떤 cell은 금지구역으로 지정되어 있어서 로봇이 접근할 수 없다.
   왼쪽 상단 꼭짓점에서 오른쪽 하단 꼭짓점으로의 경로를 찾는 알고리즘을 설계하라.
 */
#include <iostream>

using namespace std;

int row;
int col;

int load(int r, int c, int** grid) {
	if(r < 0 || c < 0 || r >= row || c >= col || grid[r][c] < 0) {
		return 0;
	}
	if(r == 0 && c == 0) {
		return 1;
	}
	
	return load(r - 1, c, grid) + load(r, c - 1, grid);
}

int main() {
	int a, b, N;
	int** grid;

	cout << "input row, col\n";
	cin >> row >> col;
	
	// init grid array (row x col size)
	grid = new int* [row];

	for(int i = 0; i < row; i ++) {
		grid[i] = new int[col](); // init grid value zero.
	}
	
	cout << "select stop cell's count\n";
	cin >> N;

	for(int i = 0; i < N; i++) {
		cout <<"input stop cell's row and column\n";
		cin >> a >> b;
		grid[a][b] = -1;
	}
	cout << "go to (n, n) = " << load(row - 1, col - 1, grid)<<"\n";
}
