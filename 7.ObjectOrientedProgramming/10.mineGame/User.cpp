#include <iostream>
#include "User.h"

using namespace std;

User::User() {}
User::~User() {}

pair<int, int> User::click() {
	pair<int, int> location;
	
	cout << "select row and column (input ex. 1 3)" << "\n";
	cin >> location.first >> location.second;

	return location;
}
