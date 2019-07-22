#include "System.h"

using namespace std;

System::System() {}

// return worker who have work number more than max
Employee* System::dispatchCall(Employee worker[], int max) {
	int unitSize = MAX_SIZE / 3;
	int start = (max - 1) * unitSize;

	for(int i=start; i<MAX_SIZE; i++) {
		if(worker[i].getStatus() == true) {
			return *worker[i];
		}
	}
	
	return NULL;
}

bool System::canSettle(Employee worker, Customer user) {
	if( worker.getWork() >= user.getRequirement() ) return true;
	else return false;
}

void System::Calling(Employee worker[], Customer user, int workNum = 1) {
	Employee *emp = dispatchCall(worker, workNum);
	int number;

	if(emp != NULL) {
		(*emp)->setStatus(false); // is calling

		cout << "[press the number what you want]" << endl;
		cin >> number;

		user.setRequirement(number);

		if(canSettle(emp, user)) {
			(*emp)->setStatus(true);
			cout << "End Calling" << endl;
		}
		else {
			workToss(worker, emp, user);
		}
	}
	else {
		cout << "Can't receive calls. Sorry\n";
	}
}

void System::workToss(Employee worker[], Employee tempWorker, Customer user) {
	int work = tempWorker.getWork();

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
			case CONTACTOR :
				emp[i].setType(CONTACTOR);
				emp[i].setWork(QUESTION);
				break;
			case MANAGER :
				emp[i].setType(MANAGER);
				emp[i].setWork(COMPLAIN);
				break;
			case VIEWER :
				emp[i].setType(VIEWER);
				emp[i].setWork(INNOVATION);
				break;
		}
	}

	Customer user = new Customer("Somang");
	
	Calling(emp, user);
}
