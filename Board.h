//mukrom karunia azza 4210191028
#include<string>
#include<iostream>
#include<fstream>
#include<time.h>
#include"Player.h"
#define boxArena 9
#pragma once

using namespace std;
class Board
{
private:
	string temp;
	string arena[9][9];
	string check[9][9];
public:
	Player theplayer;
	void drawArena(int x,int y);
	void importArena();
	void randomizeArena();
	void setArena(int x, int y,int value);
	string getArena(int i, int j)
	{
		return arena[i][j];
	}
	string getCheck(int i, int j)
	{
		return check[i][j];
	}

};
