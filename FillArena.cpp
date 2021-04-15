#include "fillArena.h"

FillArena::FillArena(Board& board, int x, int y, int input)
{
	this->b = &board;
	this->x = x;
	this->y = y;
	this->input = input;
}
