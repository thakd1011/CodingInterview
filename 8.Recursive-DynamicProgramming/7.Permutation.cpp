/*
   문제 7.
   문자열이 주어졌을 때 모든 경우의 순열을 계산하는 메서드를 작성하라.
   단, 문자는 중복되어 나타날 수 없다.
 */
// Permutation without duplication

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
   prefix를 이용한 방법
 */

// more efficiently
void permutationPrefix(string s, string temp, vector<string>& result) {
	if(s.size() == 0) {
		result.push_back(temp);
		return;
	}

	for(int i = 0; i < s.size(); i ++) {
		string prefix = temp + s.substr(i, 1); // i번째 문자
		string remain = s.substr(0, i) + s.substr(i + 1, n - 1 - i);
		permutationPrefix(remain, prefix, result);
	}
}

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
	vector<string> result;

	cout << "input string\n";
	cin >> s;
	N = s.length();
	visited = new int[N];

	permutation(s, "", visited);

	cout << "second solution\n\n";
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] <<"\n";
	}
}
