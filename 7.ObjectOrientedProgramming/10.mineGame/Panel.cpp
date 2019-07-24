#include "Panel.h"
#include <iostream>

using namespace std;

Panel::Panel() {
	direction = { {1, -1}, {1, 0}, {1, -1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1} };
}

Panel::~Panel() {
	for(int i = 0; i < panelSize; i++) {
		for(int j = 0; j < panelSize; j++) {
			delete cellArr[i][j];
		}
	}
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

// setting Cell's value (number of bombs around the cell)
void Panel::setInitBombAround(int row, int col) {
	int tempRow, tempCol;

	cellArr[row][col].setBomb(true);

	for(int i = 0; i < 8; i++) {
		tempRow = row + direction[i][0];
		tempCol = col + direction[i][1];

		if( isInPanel(tempRow, tempCol) ) {
			if( !cellArr[tempRow][tempCol].isBomb() ) {
				cellArr[tempRow][tempCol].increaseValue();
			}
		}
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
	else {
		cout << "it is out of range!\n";
	}
}

void Panel::changeFlaged(int row, int col) {
	if( cellArr[row][col].getFlag() == true ) {
		cellArr[row][col].setFlag(false);
	}
	else {
		cellArr[row][col].setFlag(true);
	}
}

void Panel::checkCellBoundary(int row, int col) {
	if( !isInPanel(row, col) || isChecked(row, col) || isBomb(row, col) || isFlaged(row, col) ) {
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
			if( !cellArr[i][j].getCheck() || !cellArr[i][j].getFlag()) {
				return false;
			}
		}
	}

	return true;
}

bool Panel::isInPanel(int row, int col) {
	if(row < 0 || col < 0 || row >= panelSize || col >= panelSize) {
		cout << "out of range! Reselect Plz\n";
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
