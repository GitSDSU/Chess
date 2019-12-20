#pragma once

#include "Constants.h"

class Piece
{
public:
	Piece(Pos, int);
	~Piece();
	virtual void Move() = 0;
protected:
	Pos position;
	int color;
};

