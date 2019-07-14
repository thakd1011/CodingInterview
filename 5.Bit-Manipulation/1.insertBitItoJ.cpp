// insert M into N at [i:j] bit
// M and N are 32 bits (N > M)
// test input : N=10000000, M = 10011, i = 2, j = 6 - system input
// output : N = 10100110
// execute sample : ./a.out N M i j
#include <iostream>
#include <math.h>
#include <cstring>
#include <bitset>

using namespace std;

int changeCharToInt(const char* binary, int len) {
	int num = 0;

	for(int i = 0; binary[i] != '\0'; i++) {
		num += pow(2, len - i - 1) * (binary[i] - '0');
		cout << binary[i];
	}

	return num;
}

int insertMN(int N, int M, int i, int j) {

	int mask_i = (1 << i) - 1; 
	int mask_j = (1 << j) - 1;
	int mask = mask_i ^ mask_j;

	N = N & (~mask);

	return (N | (M << i));
}

int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout << "insufficient arguments\n";
		exit(1);
	}

	const char *binaryN;
	const char *binaryM;
	
	int N, M, i, j;
	int result;

	binaryN = argv[1];
	binaryM = argv[2];

	i = atoi(argv[3]);
	j = atoi(argv[4]);


	N = changeCharToInt(binaryN, strlen(binaryN));
	M = changeCharToInt(binaryM, strlen(binaryM));

	result = insertMN(N, M, i, j);
	
	cout << "result = "<< bitset<32>(result)<<"\n";
}
