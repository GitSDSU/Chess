#include "stdafx.h"
#include "King.h"
#include "Board.h"


King::King(Pos pos, int c, int t) : Piece(pos, c, t)
{
	firstMove = true;
}


King::~King()
{
}


bool King::Is_Move_Valid(Pos newPos, Board &board)
{
	bool valid = false;

	if (board.Is_Square_Empty(newPos))
	{
		if (King_Move(newPos))
		{
			valid = true;
		}
		else if (Castle(newPos, board))
		{
			valid = true;
		}
	}
	else
	{
		if (King_Attack(newPos, board))
		{
			valid = true;
		}
	}

	return valid;
}

bool King::Attack_Range(Pos pos)
{
	bool valid = false;

	return valid;
}



bool King::King_Move(Pos emptySquare)
{
	bool valid = false;
	Pos displacement = emptySquare - position;
	if (displacement.Absolute(displacement.col) == 1 && displacement.Absolute(displacement.row == 1))
	{
		valid = true;
	}
	else if (displacement.Absolute(displacement.col) == 1 && displacement.row == 0)
	{
		valid = true;
	}
	else if (displacement.col == 0 && displacement.Absolute(displacement.row == 1))
	{
		valid = true;
	}
	return valid;
}


bool King::Castle(Pos emptySquare, Board &board)
{
	bool valid = false;
	Pos displacement = emptySquare - position;
	if (displacement.Absolute(displacement.col) == 2 && displacement.row == 0 && firstMove)
	{
		Pos rookPos = emptySquare;
		rookPos.col += (emptySquare.col == _G) ? 1 : -1;
		if (!board.Is_Square_Empty(rookPos))
		{
			PtrPiece rook = board.Return_Piece(rookPos);
			if (rook->Get_Type() == Type::_Rook)
			{
				//std::shared_ptr< Rook > allyRook = std::dynamic_pointer_cast< Rook > (rook);
				//if (allyRook->Is_First_Move())
				if (color == Team::White && position.col == _E && position.row == _1)
				{
					valid = true;
				}
				else if (color == Team::Black && position.col == _E && position.row == _8)
				{
					valid = true;
				}
			}
		}
	}
	return valid;
}


bool King::King_Attack(Pos, Board &)
{
	bool valid = false;

	return valid;
}














