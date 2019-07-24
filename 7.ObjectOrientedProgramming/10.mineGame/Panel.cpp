#include "Panel.h"
#include <iostream>

using namespace std;

Panel::Panel() {}

Panel::~Panel() {}

void Panel::setBombCnt(int cnt) {
	bombCnt = cnt;
}

void Panel::setPanelSize(int n) {
	panelSize = n;
}

int Panel::getBombCnt() {
	return bombCnt;
}

int Panel::getFlagCnt() {
	return flagCnt;
}

void Panel::initPanel() {
	cellArr = new Cell* [panelSize];

	for(int i = 0; i < panelSize; i++) {
		cellArr[i] = new Cell[panelSize];
	}
}

// setting Cell's value (number of bombs around the cell)
void Panel::setInitBombAround(int row, int col) {
	int tempRow, tempCol;

	cellArr[row][col].setBomb(true);

	for(int i = 0; i < 8; i++) {
		tempRow = row + direction[i][0];
		tempCol = col + direction[i][1];

		if( isInPanel(tempRow, tempCol) ) {
			if( cellArr[tempRow][tempCol].getBomb() == false) {
				cellArr[tempRow][tempCol].increaseValue();
			}
		}
	}
}



void Panel::showDisplay() {
	cout << "  ";
	for(int i = 0; i < panelSize; i++) {
		cout << i << " ";
	}
	cout <<"\n";

	for(int i = 0; i < panelSize; i++) {
		cout << i << " ";
		for(int j = 0; j < panelSize; j++) {			
			if( cellArr[i][j].getCheck() == false) {
				if( cellArr[i][j].getFlag() == true ) {
					cout << "f";
				}
				else {
					cout << "?";
				}
			}
			else {
				if( cellArr[i][j].getBomb() == true ) {
					cout << "B";
				}
				else {
					if( cellArr[i][j].getValue() == 0 ) {
					cout << ".";
					}
					else {
						cout << cellArr[i][j].getValue();
					}
				}
			}
			cout <<" ";
		}
		cout <<"\n";
	}
}

void Panel::increaseCellValue(int row, int col) {
	if( isInPanel(row, col) ){
		cellArr[row][col].increaseValue();
	}
}

void Panel::increaseFlagCnt() {
	flagCnt++;
}

void Panel::decreaseFlagCnt() {
	flagCnt--;
}

void Panel::changeFlaged(int row, int col) {
	if( cellArr[row][col].getFlag() == true ) {
		cellArr[row][col].setFlag(false);
		decreaseFlagCnt();
	}
	else {
		cellArr[row][col].setFlag(true);
		increaseFlagCnt();
	}
}

void Panel::checkCellBoundary(int row, int col) {
	if( !isInPanel(row, col) || isChecked(row, col) || isBomb(row, col) || isFlag(row, col) ) {
		return;
	}
	
	int tempRow, tempCol;
	cellArr[row][col].setCheck(true);
	
	if( cellArr[row][col].getValue() == 0) {
		for(int i = 0; i < 8; i++) {
			tempRow = row + direction[i][0];
			tempCol = col + direction[i][1];
			checkCellBoundary(tempRow, tempCol);
		}
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

bool Panel::isChecked(int row, int col) {
	if( cellArr[row][col].getCheck() == true ) {
		return true;
	}
	else {
		return false;
	}
}

bool Panel::isBomb(int row, int col) {
	if( cellArr[row][col].getBomb() == true ) {
		return true;
	}
	else {
		return false;
	}
}

bool Panel::isFlag(int row, int col) {
	if( cellArr[row][col].getFlag() == true ) {
		return true;
	}
	else {
		return false;
	}
}
