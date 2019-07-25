#include <iostream>
#include <vector>

#define MAXSIZE 100

using namespace std;

int multiply (int a, int b) {
	int big = a > b ? a : b;
	int small = a > b ? b : a;

	if(small == 0)
		return 0;

	if(small == 1)
		return big;

	int temp = small >> 1; // /2

	int first = multiply(temp, big);
	int second;
	
	if(small % 2 == 1) {
		second = first + big; //%2 == 1 equals last binary is 1
	}
	else {
		second = first;
	}

	return first + second; // 2 * (big, small/2) == 2 * (big * (small / 2)) == big * small
}

int main() {
	int A, B;
	int big, small;
	int result;
	vector<int> dp(big, -1); // init all value -1

	cout << "input two integer\n";
	cin >> A >> B;

	big = A > B ? A : B;
	small = A > B ? B : A;

	result = multiply(big, small);
	cout << "result = "<< result <<"\n";
}
