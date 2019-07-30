/*
	문제 9. 괄호
	n쌍의 괄호로 만들 수 있는 모든 합당한(괄호가 적절히 열리고 닫힌)
	조합을 출력하는 알고리즘을 구현하라.
	입력 : 3
	출력 : ((())), (()()), (())(), ()(()), ()()()
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> res;

void brackets(int open, int close, string temp) {
	if(open > close || open < 0 || close < 0) {
		return;
	}
	else if(open == 0 && close == 0) {
		res.push_back(temp);
	}
	else { // open <= close
		brackets(open - 1, close, temp + "(");
		brackets(open, close - 1, temp + ")");
	}
}

int main() {
	int N;

	cout << "input N \n";
	cin >> N;
	
	brackets(N, N, "");

	for(int i = 0; i < res.size(); i++) {
		cout << "case " << i + 1 << " = " << res[i];
		cout << "\n";
	}
}
