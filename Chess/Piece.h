#pragma once

#include "Constants.h"

class Board;

class Piece
{
public:
	Piece(Pos, int, int);
	~Piece();
	int Get_Color() const;
	int Get_Type() const;
	Pos Get_Pos() const;
	bool Is_Captured() const;
	void Capture();
	virtual bool Is_Move_Valid(Pos, Board &) = 0;
	virtual bool Attack_Range(Pos, Board &) = 0;
	virtual bool Stalemate(Pos, Board &) = 0;
	void Set_Pos(const Pos);

protected:
	Pos position;
	int color;
	int type;
	bool captured;
};

