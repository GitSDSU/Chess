#pragma once

#include "Piece.h"

class Pawn :
	public Piece
{
public:
	Pawn(Pos, int, int);
	~Pawn();
	void Move() { }
	bool Is_Move_Valid(Pos, Board &);
	bool Process_Move(Pos);
	bool Process_Attack(Pos);
	bool Enpassant(Pos, Board &);
	bool Jump_Two_Squares() const;
	bool Attack_Range(Pos);

private:
	bool twoSquares;
};

