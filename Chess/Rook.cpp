#include "stdafx.h"
#include "Rook.h"
#include "Board.h"


Rook::Rook(Pos pos, int c, int t) : Piece(pos, c, t)
{
	moveCounter = 0;
}


Rook::~Rook()
{
}


bool Rook::Is_Move_Valid(Pos newPos, Board &board)
{
	Pos displacement = newPos - position;
	Pos tempRookMove = position;
	if ((displacement.col == 0 && displacement.row != 0) || (displacement.col != 0 && displacement.row == 0))
	{
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
	moveCounter++;
	return true;
}


bool Rook::Attack_Range(Pos attackSquare, Board &board)
{
	Pos displacement = attackSquare - position;
	Pos tempRookMove;
	if ((displacement.col == 0 && displacement.row != 0) || (displacement.col != 0 && displacement.row == 0))
	{
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


bool Rook::Stalemate(Pos newPos, Board &board)
{
	Pos displacement = newPos - position;
	Pos tempRookMove;
	if ((displacement.col == 0 && displacement.row != 0) || (displacement.col != 0 && displacement.row == 0))
	{
		if (!board.Is_Square_Empty(newPos))
		{
			PtrPiece friendOrFoe = board.Return_Piece(newPos);
			if (friendOrFoe->Get_Color() == color)
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


bool Rook::First_Move() const
{
	return (moveCounter > 0) ? false : true;
}



















