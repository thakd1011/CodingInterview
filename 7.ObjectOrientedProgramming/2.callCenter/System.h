#ifndef SYSTEM_H_
#define SYSTEM_H_

#define MAX_SIZE 30

#include "Employee.h"
#include "Customer.h"
#include <stdio.h>
#include <string>

using namespace std;

class System{
	private :
		Employee emp[MAX_SIZE];
	public :
		System();
		Employee* dispatchCall(Employee worker[], int max);
		bool canSettle(Employee worker, Customer user);
		void Calling(Employee worker[], Customer user, int workNum = 1);
		void workToss(Employee worker[], Employee tempWorker, Customer user);
};

#endif
