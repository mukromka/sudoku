//bismillah 
#include"Board.h"

//mukrom karunia azza 4210191028
void Board::randomizeArena()
{
	int r;
	string cek;
	srand(time(0));
	for (int t = 0; t < 1; t++)
	{
		for (int i = 0; i < boxArena; i++)
		{
			for (int j = 0; j < boxArena; j++)
			{
				r = rand() % 10;
				cek = to_string(r);
				if (arena[i][j] == cek)
				{
					arena[i][j] = "_";
					break;
				}
			}
		}
	}
}

void Board::setArena(int x, int y,int value)
{
	if (value > 0 && value < 10)
	{
		if (arena[y][x] == "_")
			arena[y][x] = to_string(value);
	}
	value = 0;
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
			check[i][j] = temp.substr(dataTaken, 1);
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
