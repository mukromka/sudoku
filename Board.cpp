//bismillah 
#include"Board.h"
#include <windows.h> 
#define mudah 1
#define normal 10
#define expert 25
//mukrom karunia azza 4210191028
void Board::randomizeArena()
{
	int r;
	string cek;
	srand(time(0));
	if (temp2.size() <= 0)
	{
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
}

void Board::fillArena(int x, int y,int value)
{
	if (value > 0 && value < 10)
	{
		if (arena[y][x] == "_")
			arena[y][x] = to_string(value);
	}
	else if (value == 0)
		arena[y][x] = "_";
	value = 0;
	ofstream foutput;
	ifstream finput;
	finput.open("SaveBoard.txt");
	foutput.open("SaveBoard.txt");

	if (finput.is_open())
	{
		for (int i = 0; i < boxArena; i++)
		{
			for (int j = 0; j < boxArena; j++)
			{
				foutput << arena[i][j];
			}
		}
	}
	finput.close();
	foutput.close();
}
void Board::importArena()
{

	ifstream jawaban("kunci_jawaban.txt");
		if (jawaban.is_open())
		{
			while (!jawaban.eof())
			{
				getline(jawaban, temp);
			}
			jawaban.close();
		}
		ifstream saveBoard("SaveBoard.txt");
		if (saveBoard.is_open())
		{
			while (!saveBoard.eof())
			{
				getline(saveBoard, temp2);

			}
		}
		else
			cout << "File error!";
	int dataTaken = 0;
	for (int i = 0; i < boxArena; i++)
	{
		for (int j = 0; j < boxArena; j++)
		{
			if (temp2.size() <=0)
			{
				arena[i][j] = temp.substr(dataTaken, 1);
				check[i][j] = temp.substr(dataTaken, 1);
				dataTaken++;
			}
			else
			{
				arena[i][j] = temp2.substr(dataTaken, 1);
				dataTaken++;
			}
		}
	}


}

void Board::resetLevel()
{
	ofstream foutput;
	ifstream finput;
	finput.open("SaveBoard.txt");
	foutput.open("SaveBoard.txt");

	if (finput.is_open())
	{
		foutput << "";
	}
	finput.close();
	foutput.close();
}

void Board::drawArena(int x,int y)
{
	system("cls");
	cout << endl;
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

		if (i == 2)
		{
			cout << "\n  ___ ___ ___ ___ ___ ___ ___ " << "\t" << "Press W/A/S/D to move";
		}
		if (i == 5)
		{
			cout << "\n  ___ ___ ___ ___ ___ ___ ___ " << "\t" << "Press Z to Undo, Press Y to Redo" << endl;;
		}
		else
			cout << endl ;
	}
}
