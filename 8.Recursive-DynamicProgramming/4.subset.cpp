/*
   문제 4. 부분집합
   어떤 집합의 부분집합을 전부 반환하는 메서드를 작성하라.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector < vector <string> > result;

void makeSubset(vector <string> origin, vector <string> subset, int index) {
	result.push_back(subset);
	
	for(int i = index; i < origin.size(); i++) {
		vector <string> tempSet;
		for(int j = 0; j < subset.size(); j++) {
			tempSet.push_back(subset[j]);
		}
		tempSet.push_back(origin[i]);
		makeSubset(origin, tempSet, i + 1);
	}
}

int main() {
	vector <string> setList;
	vector <string> temp;

	setList.push_back("my");
	setList.push_back("name");
	setList.push_back("is");
	setList.push_back("chul");
	setList.push_back("su");
	setList.push_back("!");
	temp.push_back(" "); // empty set

	makeSubset(setList, temp, 0);

	for(int i = 0; i < result.size(); i++) {
		cout << "set " << i <<" = ";
		for(int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] <<", ";
		}
		cout <<"\n";
	}
}
