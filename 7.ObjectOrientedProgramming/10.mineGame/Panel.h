#ifndef PANEL_H_
#define PANEL_H_

#include <utility>
#include <iostream>
#include "Cell.h"
#include "Game.h"

using namespace std;

class Panel{
	private :
		int direction[8][2];
		Cell **cellArr;
		int panelSize;
		int bombCnt;

	public :
		Panel();
		~Panel();

		void setBombCnt(int cnt);
		void setPanelSize(int n);
		void getBombCnt();

		void initPanel();
		void setInitBombAround(int row, int col);

		void showDisplay();

		void increaseCellValue(int row, int col);
		void changeFlaged(int row, int col); // true->false | false->true
		void checkCellBoundary(int row, int col); // check all cell (none zero & bomb)
		
		bool allCellChecked();
		bool isInPanel(int row, int col);
		bool isChecked(int row, int col);
		bool isBomb(int row, int col);
		bool isFlag(int row, int col);
};

#endif
