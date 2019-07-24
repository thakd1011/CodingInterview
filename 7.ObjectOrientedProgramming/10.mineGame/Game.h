#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include "Panel.h"
#include "User.h"

namespace SELECTNUM {
	enum {
		CLICK,
		FLAG
	};
}

// prototyping
class Panel;
class User;

class Game{
	private :
		Panel *panel;
		User *user;
	
	public :
		Game();
		void initialize();
		void gameStart(); 
		bool canClick(int row, int col); //flag = f, check = f
		bool terminationCondition(); // check flagCnt == bombCnt
		void gameEnd(int winLose); // win = 1, lose = 0
};

#endif
