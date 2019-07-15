#include <iostream>
#include <bitset>

using namespace std;

int swapCount(int a, int b) {
	int count = 0;
	for(int res = a^b; res != 0; res = res >> 1) {
		count += res & 1;
	}
	return count;
}

int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout <<"insufficient arguments\n";
		exit(1);
	}
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	int oneCount = swapCount(a, b);

	cout << "one Count = " << oneCount <<"\n";
}
