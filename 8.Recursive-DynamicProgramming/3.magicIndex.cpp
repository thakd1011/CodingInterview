/*
   문제 3. 마술 인덱스
   배열 A[0~n-1]에서 A[i] = i인 인덱스를 마술 인덱스라 정의한다.
   정렬된 상태의 배열이 주어졌을 때, 마술 인덱스가 존재한다면 그 값을 찾는 메서드를 작성하라.
   배열 안에 중복된 값은 없다.
   +alpha : 중복된 값을 허용한다면 어떻게 풀겠는가?
 */
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

void magicIndex(int* arr, int arrIndex, int arrSize, int min, int max) {
	if( arrIndex < 0 || arrIndex >= arrSize || arrIndex < min || arrIndex > max) {
		cout << "not in magic index!\n";
		return;
	}
	if( arrIndex == arr[arrIndex] ) {
		cout << "magicIndex = " << arr[arrIndex]<<"\n";
		return;
	}

	if( arrIndex < arr[arrIndex] ) {
		magicIndex(arr, arrIndex - 1, arrSize, min, arrIndex);
	}
	else {
		magicIndex(arr, arrIndex + 1, arrSize, arrIndex, max);
	}
}
int main() {
	int *arr;
	int arrSize;

	cout << "input array size\n";
	cin >> arrSize;

	arr = new int[arrSize];

	for(int i = 0; i < arrSize; i++) {
		arr[i] = (rand() % 100) - 50; // between -50 to 50;
		cout << "arr= "<< arr[i] <<"\n";
	}
	
	sort(arr, arr + arrSize);

	magicIndex(arr, (arrSize / 2) , arrSize, -1, arrSize);
}
