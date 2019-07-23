#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include "Panel.h"
#include "User.h"

class Game{
	private :
		int direction[8][2];
		int flagCnt;
		Panel panel;
		User user;
	
	public :
		Game();
		void initialize();
		void gameStart();
		void searchEdgeCell(int row, int col); // eight direction search using dfs algorithm
		bool terminationCondition(); // check flagCnt == bombCnt
};

#endif
