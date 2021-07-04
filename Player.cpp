#include"Player.h"
//siti julekhah 4210191026

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
	else if (input == 'R' || input == 'r')
	{
		setanswer(12);//redo move
		isMove = true;
	}
	else
		isMove = false;

	return isMove;
}