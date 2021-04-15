//mukrom karunia azza 4210191028
#include"GameManager.h"

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
		cout << "\n\n\n\n\n\t\tYou Win!\n\n\n"<<endl;
		isOver = true;
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
			FillArena* command = new FillArena(*b, p->getpositionX(), p->getpositionY(), p->getanswer());
			command->excecute();
			inv->pushCommand(*command);
			//board.fillArena(player.getpositionX(), player.getpositionY(), player.getanswer());
			b->drawArena(p->getpositionX(), p->getpositionY());
			p->setanswer(0);
			gameOver = checkAnswer(gameOver);
		}
	}
}