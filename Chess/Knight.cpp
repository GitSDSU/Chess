#include "stdafx.h"
#include "Knight.h"
#include "Board.h"


Knight::Knight(Pos pos, int c, int t) : Piece(pos, c, t)
{
}


Knight::~Knight()
{
}


bool Knight::Is_Move_Valid(Pos newPos, Board &board)
{
	Pos displacement = newPos - position;
	if ((displacement.Absolute(displacement.col) == 1 && displacement.Absolute(displacement.row) == 2) ||
		(displacement.Absolute(displacement.col) == 2 && displacement.Absolute(displacement.row) == 1))
	{
		if (!board.Is_Square_Empty(newPos))
		{
			PtrPiece piece = board.Return_Piece(newPos);
			if (piece->Get_Color() == color)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}


bool Knight::Attack_Range(Pos attackSquare, Board &board)
{
	Pos displacement = attackSquare - position;
	if ((displacement.Absolute(displacement.col) == 1 && displacement.Absolute(displacement.row) == 2) ||
		(displacement.Absolute(displacement.col) == 2 && displacement.Absolute(displacement.row) == 1))
	{
		return true;
	}
	return false;
}


bool Knight::Stalemate(Pos newPos, Board &board)
{
	return Is_Move_Valid(newPos, board);
}
















