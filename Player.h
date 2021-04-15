//siti julekhah 4210191026
#pragma once
#ifndef player_h
#define player_h
#include<conio.h>
//#include"GameManager.h"
#pragma once
class Player
{
private:
	int cursorpositionX;
	int cursorpositionY;
	int answer = 0;
	//gameManager* GM;
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
char Player::getinput()
{
	char theInput = 'x';
	if (_kbhit()) {
		theInput = _getch();
	}
	else {
		theInput = 'x';
	}
	return theInput;
}

void Player::setanswer(int ans)
{
	answer = ans;
}
bool Player::moveplayer()
{
	bool isMove = false;
	char input = getinput();
	if (input == 'w' && getpositionY() != 0)
	{
		changepositonY(0);
		isMove = true;
	}
	else if (input == 'a' && getpositionX() != 0)
	{
		changepositonX(0);
		isMove = true;
	}
	else if (input == 's' && getpositionY() < 8)
	{
		changepositonY(1);
		isMove = true;
	}
	else if (input == 'd' && getpositionX() < 8)
	{
		changepositonX(1);
		isMove = true;
	}
	else if (input == '1')
	{
		setanswer(1);
		isMove = true;
	}
	else if (input == '2')
	{
		setanswer(2);
		isMove = true;
	}
	else if (input == '3')
	{
		setanswer(3);
		isMove = true;
	}
	else if (input == '4')
	{
		setanswer(4);
		isMove = true;
	}
	else if (input == '5')
	{
		setanswer(5);
		isMove = true;
	}
	else if (input == '6')
	{
		setanswer(6);
		isMove = true;
	}
	else if (input == '7')
	{
		setanswer(7);
		isMove = true;
	}
	else if (input == '8')
	{
		setanswer(8);
		isMove = true;
	}
	else if (input == '9')
	{
		setanswer(9);
		isMove = true;
	}
	else if (input == 'Z' || input == 'z')
	{
		setanswer(10);//undo move
		isMove = true;
	}
	else if (input == 'Y' || input == 'y')
	{
		setanswer(11);//redo move
		isMove = true;
	}
	else
		isMove = false;

	return isMove;
}

#endif