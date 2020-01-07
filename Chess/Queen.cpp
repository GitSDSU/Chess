#include "stdafx.h"
#include "Queen.h"
#include "Board.h"


Queen::Queen(Pos pos, int c, int t) : Piece(pos, c, t)
{
}


Queen::~Queen()
{
}


bool Queen::Is_Move_Valid(Pos newPos, Board &board)
{
	Pos displacement = newPos - position;

	if (displacement.Absolute(displacement.col) == displacement.Absolute(displacement.row))
	{	/// Bishop Move
		Pos tempBishopMove;
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
	else if ((displacement.col != 0 && displacement.row == 0) || (displacement.col == 0 && displacement.row != 0))
	{	/// Rook Move
		Pos tempRookMove;
		if (!board.Is_Square_Empty(newPos))
		{
			PtrPiece piece = board.Return_Piece(newPos);
			if (piece->Get_Color() == color)
			{
				return false;
			}
		}
		int range = (displacement.col != 0) ? displacement.col : displacement.row;
		for (int i = 1; i < displacement.Absolute(range); i++)
		{
			tempRookMove = position;
			if (range > 0)
			{
				if (displacement.col != 0)
				{
					tempRookMove.col += i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
				else
				{
					tempRookMove.row += i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
			}
			else
			{
				if (displacement.col != 0)
				{
					tempRookMove.col -= i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
				else
				{
					tempRookMove.row -= i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}


bool Queen::Attack_Range(Pos attackSquare, Board &board)
{
	Pos displacement = attackSquare - position;

	if (displacement.Absolute(displacement.col) == displacement.Absolute(displacement.row))
	{	/// Bishop Move
		Pos tempBishopMove;
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
	else if ((displacement.col != 0 && displacement.row == 0) || (displacement.col == 0 && displacement.row != 0))
	{	/// Rook Move
		Pos tempRookMove;
		int range = (displacement.col != 0) ? displacement.col : displacement.row;
		for (int i = 1; i < displacement.Absolute(range); i++)
		{
			tempRookMove = position;
			if (range > 0)
			{
				if (displacement.col != 0)
				{
					tempRookMove.col += i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
				else
				{
					tempRookMove.row += i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
			}
			else
			{
				if (displacement.col != 0)
				{
					tempRookMove.col -= i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
				else
				{
					tempRookMove.row -= i;
					if (!board.Is_Square_Empty(tempRookMove))
					{
						return false;
					}
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}


bool Queen::Stalemate(Pos newPos, Board &board)
{
	return Is_Move_Valid(newPos, board);
}



















