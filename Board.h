#include<string>
#include<iostream>
#include<fstream>
#include<time.h>
#include"Player.h"
#define boxArena 9

using namespace std;
class Board
{
private:
	string temp;
	string arena[9][9];
public:
	Player theplayer;
	void drawArena(int x,int y);
	void importArena();
	void randomizeArena();

};
