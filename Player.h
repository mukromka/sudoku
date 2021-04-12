//siti julekhah 4210191026 (masih belum, nungguin boardnya dlu)
#include<iostream>
#include<conio.h>
using namespace std;

class Player
{
private :
	int cursorpositionX;
	int cursorpositionY;

public:

	Player()
	{
		setcursordefault();
	}
	int getpositionX()
	{
		return cursorpositionX;
	}
	void changepositonX(int x)
	{
		if (x == 1)
			cursorpositionX++;
		else
			cursorpositionX--;
	}

	int getpositionY()
	{
		return cursorpositionY;
	}
	void changepositonY(int y)
	{
		if (y == 1)
			cursorpositionY++;
		else
			cursorpositionY--;
	}

	void setcursordefault()
	{
		cursorpositionX = 0;
		cursorpositionY = 0;
	}
	bool moveplayer();
	char getinput();
};
