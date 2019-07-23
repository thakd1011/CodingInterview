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
		void setBombCnt(int cnt);
		void setPanelSize(int n);
		void getBombCnt();
		void initPanel();
		void showDisplay();
		bool allCellChecked();
		void setInitBombAround(int row, int col);
		void increaseCellValue(int row, int col);
		bool isInPanel(int row, int col);
};

#endif
