#ifndef USER_H_
#define USER_H_

#include <utility>
#include "Game.h"

using namespace std;

class User{
	public :
		User();
		~User();
		pair<int, int> click();
};
#endif
