// mukrom karunia azza 4210191028
#pragma once
#ifndef GameManager_h
#define GameManager_h
#include"Player.h"
#include"Board.h"
#include "invoker.h"
#include "fillArena.h"
class gameManager
{
private :
	int checktrue = 0;
	Board* b;
	Player* p;
	Invoker* inv;
public :
	gameManager();
	void startGame();
	bool checkAnswer(bool gameOver);
};
gameManager::gameManager()
{
	p = new Player();
	b = new Board();
	inv = new Invoker();
}

bool gameManager::checkAnswer(bool isOver)
{
	isOver = false;
	for (int i = 0; i < boxArena; i++)
	{
		for (int j = 0; j < boxArena; j++)
		{
			if (b->getArena(i, j) == b->getCheck(i, j))
			{
				checktrue++;
			}
		}
	}
	if (checktrue == 81)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\tYou Win!\n\n\n" << endl;
		isOver = true;
		b->resetLevel();
	}
	else
		checktrue = 0;

	return isOver;
}
void gameManager::startGame()
{
	bool isMove = false;
	bool gameOver = false;
	b->importArena();
	b->randomizeArena();
	b->drawArena(p->getpositionX(), p->getpositionY());
	while (!gameOver)
	{
		isMove = p->moveplayer();
		if (isMove)
		{
			if (p->getanswer() != 0 && p->getanswer() < 10)
			{
				FillArena* command = new FillArena(*b, p->getpositionX(), p->getpositionY(), p->getanswer());
				command->excecute();
				inv->pushCommand(*command);
			}
			else if (p->getanswer() == 10)//means press z
				inv->popCommandUndo(); // undo move
			else if (p->getanswer() == 11)//means press y
				inv->popCommandRedo();//redo move
			else if (p->getanswer() == 12)
			{
				b->resetLevel();
				system("cls");
				b->importArena();
				b->randomizeArena();
			}
			b->drawArena(p->getpositionX(), p->getpositionY());
			p->setanswer(0);
			gameOver = checkAnswer(gameOver);
		}
	}
}
#endif