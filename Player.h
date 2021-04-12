//siti julekhah 4210191026
#include<conio.h>

class Player
{
private:
	int cursorpositionX;
	int cursorpositionY;
	int answer = 0;
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
	void setanswer(int ans);
	int getanswer()
	{
		return answer;
	}
};
