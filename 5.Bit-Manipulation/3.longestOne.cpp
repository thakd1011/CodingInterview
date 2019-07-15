// update just one bit making longest one values
// input : 11011101111
// output : 8
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>

using namespace std;

int* reverseBinary(int* N, int len) {
	int* newN = (int*)malloc(sizeof(int) * len);

	for(int i=0; i<len; i++) {
		newN[i] = (N[i] + 1) % 2;
	}

	return newN;
}

// position from back!
vector<int> positionOfOne(int* N, int len) {
	vector<int> position;

	for(int i=0; i<len; i++) {
		if(N[i]==1) {
			position.push_back(len - i - 1);
		}
	}
	return position;
}

int longestOneCount(int* N, int len, int maskNum) {
	int* mask = (int*)malloc(sizeof(int) * len);
	int* tempArr = (int*)malloc(sizeof(int) * len);
	int max = 0, tempCnt = 0;

	for(int i=len - 1; i>=0; i--) {
		mask[i] = maskNum % 2;
		maskNum /= 2;
	}


	for(int i=0; i<len; i++) {
		tempArr[i] = N[i] |  mask[i];

		if(tempArr[i] == 1) {
			tempCnt += 1;
		}
		else {
			max > tempCnt ? max = max : max = tempCnt;
			tempCnt = 0;
		}
	}
	max > tempCnt ? max = max : max = tempCnt;
	return max;
}

int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout <<"insufficient arguments\n";
		exit(1);
	}

	const char *binaryN = argv[1];
	int* N;
	int* notN;
	int binaryLen = strlen(binaryN);
	int oneCount = 0;

	N = (int*)malloc(sizeof(int)*binaryLen);
	notN = (int*)malloc(sizeof(int)*binaryLen);

	for(int i=0; i<binaryLen; i++) {
		N[i] = binaryN[i] - '0';
	}

	notN = reverseBinary(N, binaryLen);
	
	vector<int> position = positionOfOne(notN, binaryLen);

	for(int i=0; i<position.size(); i++) {
		int j = 1 << position[i];
		int tempCount = longestOneCount(N, binaryLen, j);

		oneCount = max(tempCount, oneCount);
	}

	cout << "longest one length = "<<oneCount <<"\n";
}

