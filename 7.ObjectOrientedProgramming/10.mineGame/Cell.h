#ifndef CELL_H_
#define CELL_H_

class Cell{
	private :
		bool flag;
		bool check;
		bool bomb;
		int value;

	public :
		Cell();
		~Cell();
		bool getFlag();
		bool getCheck();
		bool getBomb();
		int getValue();

		void setFlag(bool flag);
		void setCheck(bool check);
		void setBomb(bool bomb);
		void setValue(int value);

		void increaseValue();
};

#endif
