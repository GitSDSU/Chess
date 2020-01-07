#pragma once
#include "Piece.h"
class Queen :
	public Piece
{
public:
	Queen(Pos, int, int);
	~Queen();
	bool Is_Move_Valid(Pos, Board &);
	bool Attack_Range(Pos, Board &);
	bool Stalemate(Pos, Board &);
};

