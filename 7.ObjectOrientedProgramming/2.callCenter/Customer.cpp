#include "Customer.h"
#include <string>
using namespace std;

Customer::Customer() {} //empty constructor

Customer::Customer(string name) {
	this->name = name;
}

int Customer::getRequirement() {
	return requirement;
}

string Customer::getName() {
	return name;
}

void Customer::setRequirement(int requirement){
	this->requirement = requirement;
}

void Customer::setName(string name) {
	this->name = name;
}
