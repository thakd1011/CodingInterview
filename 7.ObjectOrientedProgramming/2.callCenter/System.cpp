#include "System.h"
#include <string>
#include <iostream>

using namespace std;

System::System() {}

// return worker who have work number more than max
Employee* System::dispatchCall(Employee worker[], int max) {
	int unitSize = MAX_SIZE / 3;
	int start = (max - 1) * unitSize;

	for(int i=start; i<MAX_SIZE; i++) {
		if(worker[i].getStatus() == true) {
			return &worker[i];
		}
	}
	
	return NULL;
}

bool System::canSettle(Employee worker, Customer user) {
	if( worker.getWork() >= user.getRequirement() ) return true;
	else return false;
}

void System::Calling(Employee worker[], Customer user, int workNum) {
	Employee* emp = dispatchCall(worker, workNum);
	int number;

	if(emp != NULL) {
		emp->setStatus(false); // is calling

		cout << "[press the number what you want]" << endl;
		cin >> number;

		user.setRequirement(number);

		if(canSettle(*emp, user)) {
			emp->setStatus(true);
			cout << "End Calling\n";
		}
		else {
			workToss(worker, *emp, user);
		}
	}
	else {
		cout << "Can't receive calls. Sorry\n";
	}
}

void System::workToss(Employee worker[], Employee tempWorker, Customer user) {
	int work = tempWorker.getWork();
	
	cout << "recalling higher employee...\n";
	tempWorker.setStatus(true);
	Calling(worker, user, work + 1);
}

int main() {
	Employee *emp = new Employee[MAX_SIZE];
	int type = 0;
	int divideSize = MAX_SIZE / 3;

	// init employee array
	for(int i = 0; i < MAX_SIZE; i++) {
		type = (i / divideSize) + 1;
		switch(type) {
			case TYPE::CONTACTOR :
				emp[i].setType(TYPE::CONTACTOR);
				emp[i].setWork(WORK::QUESTION);
				break;
			case TYPE::MANAGER :
				emp[i].setType(TYPE::MANAGER);
				emp[i].setWork(WORK::COMPLAIN);
				break;
			case TYPE::VIEWER :
				emp[i].setType(TYPE::VIEWER);
				emp[i].setWork(WORK::INNOVATION);
				break;
		}
	}

	Customer *user = new Customer("Somang");
	System *sys = new System();
	
	sys->Calling(emp, *user, 1);
}
