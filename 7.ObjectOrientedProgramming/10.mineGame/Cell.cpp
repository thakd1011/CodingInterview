#include "Cell.h"

Cell::Cell() {	
	this.flag = false;
	this.check = false;
	this.bomb = false;
	this.value = 0;
}

Cell::~Cell() {}

bool Cell::getFlag(){
	return this.flag;
}

bool Cell::getCheck(){
	return this.check;
}

bool Cell::getBomb(){
	return this.bomb;
}

int Cell::getValue(){
	return this.value;
}

void Cell::setFlag(bool flag){
	this.flag = flag;
}

void Cell::setCheck(bool check){
	this.check = check;
}

void Cell::setBomb(bool bomb){
	this.bomb = bomb;
}

void Cell::setValue(int value){
	this.value = value;
}

void Cell::increaseValue(){
	value += 1;
}
