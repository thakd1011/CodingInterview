/*
   문제 7.
   문자열이 주어졌을 때 모든 경우의 순열을 계산하는 메서드를 작성하라.
   단, 문자는 중복되어 나타날 수 없다.
 */
// Permutation without duplication

#include <iostream>
#include <string>

using namespace std;

// TODO : 시간복잡도 구해보기
bool allVisited(int* visited, int size) {
	for(int i = 0; i < size; i++) {
		if( !visited[i] ) {
			return false;
		}
	}
	return true;
}

void permutation(string s, string temp, int* visited) {

	if( allVisited(visited, s.length()) ) {
		cout << temp << "\n";
		return;
	}

	for(int i = 0; i < s.size(); i++) {
		if( !visited[i] ) {
			visited[i] = 1;
			permutation(s, temp + s[i], visited);
			visited[i] = 0;
		}
	}
}

int main() {
	string s;
	int N;
	int* visited;

	cout << "input string\n";
	cin >> s;
	N = s.length();
	visited = new int[N];

	permutation(s, "", visited);
}
