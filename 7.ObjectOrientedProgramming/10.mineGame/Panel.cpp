#include "Panel.h"

using namespace std;

Panel::Panel() {
	direction = { {1, -1}, {1, 0}, {1, -1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1} };
}

void Panel::setBombCnt(int cnt) {
	bombCnt = cnt;
}

void Panel::setPanelSize(int n) {
	panelSize = n;
}

int Panel::getBombCnt() {
	return bombCnt;
}

void Panel::initPanel() {
	cellArr = new Cell* [panelSize];

	for(int i = 0; i < panelSize; i++) {
		cellArr[i] = new Cell[panelSize];
	}
}

void Panel::showDisplay() {
	for(int i = 0; i < panelSize; i++) {
		for(int j = 0; j < panelSize; j++) {			
			if( !cellArr[i][j].isClicked() ) {
				if( cellArr[i][j].getFlag() ) {
					cout << "f";
				}
				else {
					cout << "?";
				}
			}
			else {
				if( cellArr[i][j].isBomb() ) {
					cout << "B";
				}
				else if( cellArr[i][j].getValue() == 0 ) {
					cout << ".";
				}
				else {
					cout << cellArr[i][j].getValue();
				}
			}
			cout <<" ";
		}
		cout <<"\n";
	}
}

bool Panel::allCellChecked() {
	for(int i = 0; i < panelSize; i++) {
		for(int j = 0; j < panelSize; j++) {
			if( !cellArr[i][j].getCheck() && !cellArr[i][j].getFlag()) {
				return false;
			}
		}
	}

	return true;
}

bool Panel::isInPanel(int row, int col) {
	if(row < 0 || col < 0 || row >= panelSize || col >= panelSize) {
		return false;
	}
	else {
		return true;
	}
}

// setting Cell's value (number of bombs around the cell)
void Panel::setInitBombAround(int row, int col) {
	int tempRow, tempCol;

	cellArr[row][col].setBomb(true);

	for(int i = 0; i < 8; i++) {
		tempRow = direction[i][0];
		tempCol = direction[i][1];

		if( isInPanel(tempRow, tempCol) ) {
			cellArr[tempRow][tempCol].increaseValue();
		}
	}
}

void Panel::increaseCellValue(int row, int col) {
	if( isInPanel(row, col) ){
		cellArr[row][col].increaseValue();
	}
	else {
		cout << "it is out of range!\n";
	}
}
