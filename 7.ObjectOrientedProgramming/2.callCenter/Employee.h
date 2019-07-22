#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

namespace TYPE{
	enum {
		CONTACTOR = 1,
		MANAGER,
		VIEWER
	};
}

namespace WORK{
	enum {
		QUESTION = 1,
		COMPLAIN,
		INNOVATION
	};
}

class Employee{
	private :
		int type;
		int work;
		bool status;
	public :
		Employee();
		Employee(int type, int work, bool status);
		int getType();
		int getWork();
		bool getStatus();
		void setType(int type);
		void setWork(int work);
		void setStatus(bool status);
};

#endif
