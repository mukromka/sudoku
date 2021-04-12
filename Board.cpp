//bismillah 
#include"Board.h"


//mukrom karunia azza 4210191028
void Board::randomizeArena()
{
	int repeat = 0;
	while (repeat < 10)
	{
		int r;
		int* i = new int;
		srand(int(i));
		delete i;
		r = rand() % 10;
		string cek = to_string(r);
		for (int i = 0; i < boxArena; i++)
		{
			for (int j = 0; j < boxArena; j++)
			{
				if (arena[i][j] == cek)
					arena[i][j] = " ";
				repeat++;
			}
		}
	}
	

}
void Board::importArena()
{
	ifstream jawaban("kunci_jawaban.txt");
	if (jawaban.is_open())
	{
		int i = 0;
		while (!jawaban.eof())
		{
			getline(jawaban, temp);
			i++;
		}
		jawaban.close();
	}
	else
		cout << "File error!";
	int dataTaken = 0;
	for (int i = 0; i < boxArena; i++)
	{
		for (int j = 0; j < boxArena; j++)
		{
			arena[i][j] = temp.substr(dataTaken, 1);
			dataTaken++;
		}
	}

}


void Board::drawArena(int x,int y)
{
	system("cls");
	for (int i = 0; i < boxArena; i++)
	{
		for (int j = 0; j < boxArena; j++)
		{
			if (j > 0) {
				if (j == 3 || j == 6)
					cout << "| ";
				else
					cout << "  ";
			}
			else {
				cout << "   ";
			}
			cout << arena[i][j];
		}
		cout << endl << "  ";
		for (int j = 0; j < boxArena; j++)
		{
			if (x == j && y == i)
				cout << " ^ ";
			else
				cout << "   ";
		}

		if (i == 2 || i == 5)
		{
			cout << "\n  ___ ___ ___ ___ ___ ___ ___ " << endl;
		}
		else
			cout << endl << endl;

	}
}

int main()
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
			board.drawArena(player.getpositionX(),player.getpositionY());
		//gameOver = true;
	}
}