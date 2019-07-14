using namespace std;

// ith bit == 1 -> return true, else false
bool getBit(int num, int i) {
	return ((num & (1 << i)) != 0);
}

// ith bit set 1
int setBit(int num, int i) {
	return num | (1 << i);
}

// ith bit set 0 (delete i bit)
int clearBit(int num, int i) {
	return (num & (~(1 << i)));
}

// delete first to ith bit
int clearBitsFirstToIth(int num, int i) {
	int mask = (1 << i) - 1;
	return num & mask;
}

// delete i to 0 bit
int clearBitsITo0(int num, int i) {
	int mask = (-1 << (i + 1));
	return num & mask;
}

// change i-th bit to v
int updateBit(int num, int i, boolean bitIs1) {
	int value = bitIs1 ? 1 : 0;
	int mask = ~(1 << i);
	return (num & mask) | (value << 1);
}
