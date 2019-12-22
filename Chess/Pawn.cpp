#include "stdafx.h"
#include "Pawn.h"


Pawn::Pawn(Pos pos, int c, int t) : Piece(pos, c, t)
{
}


Pawn::~Pawn()
{
}


bool Pawn::Is_Move_Valid(Pos newPos, Board &board)
{
	if (color == Team::White)
	{

	}
	else
	{

	}
	return false;
}



