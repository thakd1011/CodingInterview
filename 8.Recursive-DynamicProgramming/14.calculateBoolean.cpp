/*
	문제 14. 불린값 계산
	0(false), 1(true), &(AND), |(OR), ^(XOR)로 구성된 불린 표현식과
	원하는 계산 결과(역시 불린값)가 주어졌을 때, 표현식에 괄호를 적절하게 추가하여
	그 값이 원하는 결과값과 같게 만들 수 있는 모든 경우의 개수를 출력하는 함수를 구현하라.
	예시 :countEval("1^0|0|1", false) -> 2
	countEval("0&0&0&1^1|0", true) -> 10
 */

/*
   원하는 답은 false
   전체 통으로, 2개로 나눌 경우 -> 연산자 종류에 따라서 왼쪽, 오른쪽의 true & false 값이
   달라지게 되어있다....
   전체 : 순차 계산 -> 1|0|1 = 1 true니까 경우의 수에 포함 안해
   연산자 기준으로 나눠
 */

#include <iostream>
#include <string>

using namespace std;

bool stringToBool(string s) {
	if( s == "1" ) return 1;
	else if( s == "0" ) return 0;
}

int countEval(string s, bool ans) {
	if(s.length() == 0) return 0;
	if(s.length() == 1) return stringToBool(s) == ans ? 1 : 0;

	int cnt = 0;
	string left, right, op;

	for(int i = 1; i < s.length(); i += 2) {
		op = s[i];
		left = s.substr(0, i);
		right = s.substr(i + 1);

		int leftTrue = countEval(left, true);
		int rightTrue = countEval(right, true);
		int leftFalse = countEval(left, false);
		int rightFalse = countEval(right, false);

		// tempResult :: left, right의 true, false 모든 조합의 경우의 수!
		int tempResult = (leftTrue + leftFalse) * (rightTrue + rightFalse);

		int trueCnt = 0;

		if(op == "^") {
			trueCnt = leftTrue * rightFalse + leftFalse * rightTrue; // XOR이 참일 조건
		}
		else if(op == "&") {
			trueCnt = leftTrue * rightTrue;
		}
		else if(op == "|") {
			trueCnt = leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;
		}

		// trueCnt & falseCnt counting and add total count
		int subCnt;
		if(ans == true) {
			subCnt = trueCnt;
		}
		else {
			subCnt = tempResult - trueCnt;
		}
		cnt += subCnt;
	}

	return cnt;
}

int main() {
	string s;
	string want;
	bool ans;

	cout << "input boolean string and answer what you want\n";
	cin >> s >> want;

	if(want.length() == 5) {
		ans = false;
	}
	else {
		ans = true;
	}
	cout << "number of cases = " <<  countEval(s, ans) << "\n";
}

