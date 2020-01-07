#include "stdafx.h"
#include "Bishop.h"
#include "Board.h"


Bishop::Bishop(Pos pos, int c, int t) : Piece(pos, c, t)
{
}


Bishop::~Bishop()
{
}


bool Bishop::Is_Move_Valid(Pos newPos, Board &board)
{
	Pos displacement = newPos - position;
	Pos tempBishopMove;
	if (displacement.Absolute(displacement.col) == displacement.Absolute(displacement.row))
	{
		if (!board.Is_Square_Empty(newPos))
		{
			PtrPiece piece = board.Return_Piece(newPos);
			if (piece->Get_Color() == color)
			{
				return false;
			}
		}
		int range = displacement.col;
		for (int i = 1; i < range; i++)
		{
			tempBishopMove = position;
			tempBishopMove.col += (displacement.col > 0) ? 1 : -1;
			tempBishopMove.row += (displacement.row > 0) ? 1 : -1;
			if (!board.Is_Square_Empty(tempBishopMove))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}


bool Bishop::Attack_Range(Pos attackSquare, Board &board)
{
	Pos displacement = attackSquare - position;
	Pos tempBishopMove;
	if (displacement.Absolute(displacement.col) == displacement.Absolute(displacement.row))
	{
		int range = displacement.col;
		for (int i = 1; i < range; i++)
		{
			tempBishopMove = position;
			tempBishopMove.col += (displacement.col > 0) ? 1 : -1;
			tempBishopMove.row += (displacement.row > 0) ? 1 : -1;
			if (!board.Is_Square_Empty(tempBishopMove))
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}


bool Bishop::Stalemate(Pos newPos, Board &board)
{
	return Is_Move_Valid(newPos, board);
}













