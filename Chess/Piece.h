#pragma once

#include "Constants.h"

class Board;

class Piece
{
public:
	Piece(Pos, int, int);
	~Piece();
	virtual void Move() = 0;
	int Get_Color() const;
	int Get_Type() const;
	virtual bool Is_Move_Valid(Pos, Board &) = 0;
	virtual bool Attack_Range(Pos) = 0;

protected:
	Pos position;
	int color;
	int type;
};

