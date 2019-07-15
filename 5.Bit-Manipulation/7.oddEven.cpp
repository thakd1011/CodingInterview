#include <iostream>
#include <bitset>

using namespace std;

int changeOddEven(int num) {
	return (((num & 0xaaaaaaaa) >>1) | ((num & 0x55555555) << 1));
}

int main(const int argc, const char* argv[]) {
	if(argc<2) {
		cout << "insufficient arguments\n";
		exit(1);
	}

	int num = atoi(argv[1]);
	int changedNum = changeOddEven(num);
	
	cout << "original bit = "<< bitset<32>(num) <<"\n";
	cout << "changed bit = "<< bitset<32>(changedNum) <<"\n";

}
