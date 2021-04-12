//mukrom karunia azza 4210191028
#include"GameManager.h"
Board board;
Player player;
bool gameManager::checkAnswer(bool isOver)
{
	isOver = false;
	for (int i = 0; i < boxArena; i++)
	{
		for (int j = 0; j < boxArena; j++)
		{
			if (board.getArena(i, j) == board.getCheck(i, j))
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
	board.importArena();
	board.randomizeArena();
	board.drawArena(player.getpositionX(), player.getpositionY());
	while (!gameOver)
	{
		isMove = player.moveplayer();
		if (isMove)
		{
			board.setArena(player.getpositionX(), player.getpositionY(), player.getanswer());
			board.drawArena(player.getpositionX(), player.getpositionY());
			player.setanswer(0);
			gameOver = checkAnswer(gameOver);
		}
	}
}