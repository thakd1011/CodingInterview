#include "Employee.h"

Employee::Employee() {
	this.status = true; // can calling
}

Employee::Employee(int type, int work, bool status) {
	this->type = type;
	this->work = work;
	this->status = status;
}

int Employee::getType() {
	return type;
}

int Employee::getWork() {
	return work;
}

bool Employee::getStatus() {
	return status;
}

void Employee::setType(int type) {
	this->type = type;
}

void Employee::setWork(int work) {
	this->work = work;
}

void Employee::setStatus(bool status) {
	this->status = status;
}
