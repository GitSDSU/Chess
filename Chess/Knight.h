#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight(Pos, int, int);
	~Knight();
	bool Is_Move_Valid(Pos, Board &);
	bool Attack_Range(Pos, Board &);
	bool Stalemate(Pos, Board &);
};

