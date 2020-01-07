#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook(Pos, int, int);
	~Rook();
	bool Is_Move_Valid(Pos, Board &);
	bool Attack_Range(Pos, Board &);
	bool Stalemate(Pos, Board &);
	bool First_Move() const;
private:
	int moveCounter;
};

