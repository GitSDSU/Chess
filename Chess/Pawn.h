#pragma once

#include "Piece.h"

class Pawn :
	public Piece
{
public:
	Pawn(Pos, int, int);
	~Pawn();
	bool Is_Move_Valid(Pos, Board &);
	bool Process_Move(Pos, Board &);
	bool Process_Attack(Pos, Board &);
	bool Enpassant(Pos, Board &);
	bool First_Move() const;
	bool Attack_Range(Pos, Board &);
	bool Stalemate(Pos, Board &);

private:
	bool firstMove;
	int moveCounter;
};

