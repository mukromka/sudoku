#include"GameManager.h"

void gameManager::startGame()
{
	Board board;
	Player player;
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
		}
		//gameOver = true;
	}
}