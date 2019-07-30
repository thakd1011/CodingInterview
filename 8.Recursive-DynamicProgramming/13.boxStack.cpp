/*
   문제 13. 박스 쌓기
   너비 w, 높이 h, 깋ㅍ이 d인 박스 n개가 있다.
   상자는 회전시킬 수 없으며, 다른 상자 위에 올려 놓을 수 있다.
   단, 아래 놓인 상자의 너비, 높이, 깊이가 위에 놓인 상자의 너비, 높이, 깊이보다 더 클 때에만 가능하다.
   이 상자들로 쌓을 수 있는 가장 높은 답을 구하는 메서드를 작성하라.
   탑의 높이는 탑을 구성하는 모든 상자 높이의 합이다.
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Box{
	public :
		int width;
		int height;
		int depth;
		Box(int w, int h, int d);
};

Box::Box(int w, int h, int d) {
	width = w;
	height = h;
	depth = d;
}

// overloading
bool operator <(const Box &a, const Box &b) {
	return a.depth > b.depth;
}

bool canStack(int bottom, int up, vector<Box>& b) {
	if(b[bottom].width >= b[up].width && b[bottom].height >= b[up].height) {
		return true;
	}
	else {
		return false;
	}
}

void stackBox(int idx, vector<Box>& boxes, int depthSum, int* maxDepth) {
	if(idx >= boxes.size() ) {
		return;
	}

	for(int i = idx + 1; i < boxes.size(); i++) {
		if( canStack(idx, i, boxes) ){
			maxDepth[idx] = max(maxDepth[idx], depthSum + boxes[i].depth);
			stackBox(i, boxes, depthSum + boxes[i].depth, maxDepth);
		}
	}
}

int main() {
	int N;
	int* maxDepth;
	int result;

	cout << "input box count N : ";
	cin >> N;

	vector<Box> boxes;
	maxDepth = new int[N];

	for(int i = 0; i < N; i++) {
		boxes.push_back(Box( rand() % (2*N) + 1, rand() % (2*N) + 1, rand() % (2*N) + 1));
	}

	// decrease
	sort(boxes.begin(), boxes.end());

	for(int i = 0; i < N; i++) {
		maxDepth[i] = boxes[i].depth;
	}

	stackBox(0, boxes, boxes[0].depth, maxDepth);

/*
	for(int i = 0; i < N; i++) {
		cout << i <<"th box = " << boxes[i].width << ", " << boxes[i].height <<", " <<boxes[i].depth <<"\n";
	}
	
	for(int i = 0; i < N; i++) {
		cout << i <<"th maxDepth = " << maxDepth[i] <<"\n";
	}
	*/
	for(int i = 0; i < N; i++) {
		result = max(result, maxDepth[i]);
	}
	
	cout << "max Depth = "<< result <<"\n";
}
