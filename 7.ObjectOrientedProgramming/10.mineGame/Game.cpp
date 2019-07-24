#include <iostream>
#include <utility>
#include "Game.h"

using namespace std;

/*
namespace SELECTNUM {
	enum {
		CLICK,
		FLAG
	};
}
*/

Game::Game() {
	direction = { {1, -1}, {1, 0}, {1, -1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1} };
	this.flagCnt = 0;
	this.panel = new Panel();
	this.User = new User();
}

// game initial setting
void Game::initialize() {
	int n;
	int bombCnt;
	int tempRow, tempCol;

	cout << "push n for mineSweeper panels' size\n";
	cin >> n;
	
	panel.setPanelSize(n);
	panel.initPanel();

	cout << "push Bomb count for initSetting\n";
	cin >> bombCnt;

	// set bomb location and around bomb count
	panel.setBombCnt(bombCnt);
	panel.showDisplay();

	cout << "select " << bombCnt << " bomb location\n";
	for(int i = 0; i < bombCnt; i++) {
		cout << "input (row, col)\n";
		cin >> tempRow >> tempCol;

		panel.setInitBombAround(tempRow, tempCol);
	}
}

void Game::gameStart() {
	int selectNum;
	pair<int, int> selectLocation;
	int userRow, userCol;
	
	while( terminationCondition() == false ){
		do{
			selectLocation = user.click();

			userRow = selectLocation.first;
			userCol = selectLocation.second;

		}while( !panel.isInPanel(userRow, userCol) )
	
		cout << "choose flag(1) or click(0)\n";
		cin >> selectNum;

		switch(selectNum) {
			case SELECTNUM::CLICK :
				if( !canClick() ) {
					cout << "You can't click this cell\n";
				}
				else {
					if( panel.isBomb(userRow, userCol) ) {
						panel.showDisplay();
						gameEnd(0); // lose
					}

					// not bomb!
					panel.checkBoundaryCell(userRow, userCol);
					panel.showDisplay();
				}
				break;

			case SELECTNUM::FLAG :
				if( panel.isChecked() ) {
					cout << "It was checked!\n";
				}
				else {
					flagCnt++;
					panel.changeFlaged(userRow, userCol);
					panel.showDisplay();
				}

				break;
		}

		if( terminationCondition() ) {
			gameEnd(1);
		}
	}
}

bool Game::canClick(int row, int col) {
	if( !panel.isFlag(row, col) && !panel.isChecked(row, col) ) {
		return true;
	}
	else {
		return false;
	}
}

// All Cell check && flag count == bomb count, 
bool Game::terminationCondition() {
	if( !panel.allCellChecked() ) {
		return false;
	}
	else {
		if(flagCnt > panel.getBombCnt() ) {
			cout << "You must release" << flagCnt - panel.getBombCnt() << " flag, and choose cell you click\n";
			return false;
		}
		else {
			return true;
		}
	}
}

void Game::gameEnd(int winLose) {
	if(winLose == 1) {
		cout << "You Win!\n";
	}
	else {
		cout << "You Lose\n";
	}
	delete panel;
	delete user;
}
