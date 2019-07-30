/*
   이미지 편집 프로그램에서 흔히 쓰이는 영역 칠하기 함수를 구현하라.
   영역 칠하기 함수는 화면(색이 칠해진 이차원 배열)과 그 화면상의 한 지점,
   그리고 새로운 색상이 주어졌을 때,
   주어진 지점과 색이 같은 주변 영역을 새로운 색상으로 다시 색칠한다.
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void paintFill(vector< vector<int> >& board, vector< vector<int> >& visited, int row, int col, int color) {
	if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
		return;
	}
	if(visited[row][col]) {
		return;
	}

	visited[row][col] = 1;
	if(board[row][col] == color) {
		board[row][col] = 4;
	}

	for(int i = 0; i < 4; i++) {
		paintFill(board, visited, row + dir[i][0], col + dir[i][1], color);
	}
}

int main() {
	vector< vector<int> > board;
	vector< vector<int> > visited;
	int N, M, A, B;

	cout << "input screen size N x M, N&M\n";
	cin >> N >> M;

	cout << "input changed colors location\n";
	cin >> A >> B;

	for(int i = 0; i < N; i++) {
		vector<int> temp(M);
		board.push_back(temp);
		visited.push_back(temp);
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			board[i][j] = rand() % 3 + 1;
			visited[i][j] = 0;
		}
	}

	cout << "temp board\n";
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cout << board[i][j] <<" ";
		}
		cout << "\n";
	}

	cout << "==============\n";
	
	paintFill(board, visited, A, B, board[A][B]);
	cout << "new board\n";

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cout << board[i][j] <<" ";
		}
		cout << "\n";
	}
}
