/*
   문제 5. 재귀 곱셈
   연산자를 사용하지 않고 양의 정수 두 개를 곱하는 재귀함수를 작성하라.
   덧셈, 뺄셈, 비트 시프팅 연산자를 사용할 수 있지만 이들의 사용 횟수를 최소화 해야 한다.
 */

#include <iostream>
#include <vector>

using namespace std;

int countIndice(int num) {
	int indice = -1;
	while(num != 0) {
		indice++;
		num = num >> 1;
	}
	return indice;
}

int main() {
	int A, B, result;
	int temp;
	int shiftCnt;
	int diff;

	cout << "input two positive integer value\n";
	cin >> A >> B;
	
	// A is bigger than B
	if(A < B) {
		temp = A;
		A = B;
		B = temp;
	}
	
	shiftCnt = countIndice(B); // total count + log(B);
	result = A << shiftCnt;

	diff = B - (1 << shiftCnt); // total count + 2;
	for(int i = 0; i < diff; i++) {
		result += A;
	}

	cout << A <<" * "<< B <<" = "<< result <<"\n";
}
