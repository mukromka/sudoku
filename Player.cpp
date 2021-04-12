#include"Player.h"

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

bool Player::moveplayer()
{
	bool isMove;
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
	else if (input == 's' && getpositionY() < 10)
	{
		changepositonY(1);
		isMove = true;
	}
	else if (input == 'd' && getpositionX() < 10)
	{
		changepositonX(1);
		isMove = true;
	}
	else
		isMove = false;

	return isMove;
}