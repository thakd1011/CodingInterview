#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

using namespace std;

namespace REQUIREMENT{
	enum {
		QUESTION = 1,
		COMPLAIN,
		INNOVATION
	};
}

class Customer {
	private :
		string name;
		int requirement;
	public :
		Customer();
		Customer(string name);
		int getRequirement();
		string getName();
		void setRequirement(int requirement);
		void setName(string name);
};

#endif
