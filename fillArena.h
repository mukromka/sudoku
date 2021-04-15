#pragma once
#ifndef fillBoard_h
#define fillBoard_h

#include "Board.h"
#include "command.h"

class FillArena : public Command
{
private :
	Board* b;
	int x, y, input;
	int und = 0;
public :
	FillArena() = default;
	FillArena(Board& board, int x, int y, int input)
	{
		this->b = &board;
		this->x = x;
		this->y = y;
		this->input = input;
	}
	void excecute()
	{
		b->fillArena(x, y, input);
	}
	void undo()
	{
		b->fillArena(x, y, und);
	}
	void redo()
	{
		b->fillArena(x, y, input);
	}
};
#endif