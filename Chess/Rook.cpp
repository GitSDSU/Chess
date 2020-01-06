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
	bool valid = true;
	Pos displacement = newPos - position;
	Pos tempRookMove = position;
	if ((displacement.col == 0 && displacement.row != 0) || (displacement.col != 0 && displacement.row == 0))
	{
		int range = (displacement.col != 0) ? displacement.col : displacement.row;
		if (board.Is_Square_Empty(newPos))
		{
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
							valid = false;
						}
					}
					else
					{
						tempRookMove.row += i;
						if (!board.Is_Square_Empty(tempRookMove))
						{
							valid = false;
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
							valid = false;
						}
					}
					else
					{
						tempRookMove.row -= i;
						if (!board.Is_Square_Empty(tempRookMove))
						{
							valid = false;
						}
					}
				}
			}
		}
		else
		{
			PtrPiece enemyPiece = board.Return_Piece(newPos);
			if (enemyPiece->Get_Color() != color)
			{
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
								valid = false;
							}
						}
						else
						{
							tempRookMove.row += i;
							if (!board.Is_Square_Empty(tempRookMove))
							{
								valid = false;
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
								valid = false;
							}
						}
						else
						{
							tempRookMove.row -= i;
							if (!board.Is_Square_Empty(tempRookMove))
							{
								valid = false;
							}
						}
					}
				}
				if (valid)
				{
					enemyPiece->Capture();
					board.Remove_Piece(newPos);
				}
			}
		}
	}
	return valid;
}


bool Rook::Attack_Range(Pos, Board &)
{
	bool valid = false;

	return valid;
}


bool Rook::Stalemate(Pos, Board &)
{
	bool valid = false;

	return valid;
}


bool Rook::First_Move() const
{
	return (moveCounter > 1) ? true : false;
}



















