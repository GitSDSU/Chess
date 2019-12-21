#pragma once

#include "Constants.h"

class Piece
{
public:
	Piece(Pos, int, int);
	~Piece();
	virtual void Move() = 0;
	int Get_Color() const;
	int Get_Type() const;

protected:
	Pos position;
	int color;
	int type;
};

