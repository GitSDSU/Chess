#include "stdafx.h"
#include "Pawn.h"
#include "Board.h"


Pawn::Pawn(Pos pos, int c, int t) : Piece(pos, c, t)
{
	twoSquares = false;
}


Pawn::~Pawn()
{
}


bool Pawn::Is_Move_Valid(Pos newPos, Board &board)
{
	bool valid_move = false;
	PtrPiece temporary_piece;
	if (twoSquares)
	{
		twoSquares = false;
	}
	if (board.Is_Square_Empty(newPos))
	{
		if (Enpassant(newPos, board))
		{
			valid_move = true;
		}
		else if (Process_Move(newPos))
		{
			valid_move = true;
		}
	}
	else
	{
		temporary_piece = board.Return_Piece(newPos);
		if (temporary_piece->Get_Color() != color)
		{
			if (Process_Attack(newPos))
			{
				valid_move = true;
			}
		}
	}
	return valid_move;
}


bool Pawn::Process_Move(Pos emptySquare)
{
	bool valid = false;
	Pos displacement = emptySquare - position;
	if (color == Team::White)
	{
		if (displacement.col == 0 && displacement.row == 1)
		{
			valid = true;
		}
		else if (displacement.col == 0 && displacement.row == 2 && position.row == _2)
		{
			valid = true;
			twoSquares = true;
		}
	}
	else
	{
		if (displacement.col == 0 && displacement.row == -1)
		{
			valid = true;
		}
		else if (displacement.col == 0 && displacement.row == -2 && position.row == _7)
		{
			valid = true;
			twoSquares = true;
		}
	}
	return valid;
}


bool Pawn::Process_Attack(Pos enemyPos)
{
	bool valid = false;
	Pos displacement = enemyPos - position;
	if (color == Team::White)
	{
		if (displacement.Absolute(displacement.col) == 1 && displacement.row == 1)
		{
			valid = true;
		}
	}
	else
	{
		if (displacement.Absolute(displacement.col) == 1 && displacement.row == -1)
		{
			valid = true;
		}
	}
	return valid;
}


bool Pawn::Enpassant(Pos enpassantSquare, Board &board)
{
	bool valid = false;
	PtrPiece enemyPiece;
	Pos enemySquare;
	enemySquare.col = enpassantSquare.col;
	enemySquare.row = (color == Team::White) ? enpassantSquare.row - 1 : enpassantSquare.row + 1;
	if (!board.Is_Square_Empty(enemySquare))
	{
		enemyPiece = board.Return_Piece(enemySquare);
		if (enemyPiece->Get_Color() != color && enemyPiece->Get_Type() == Type::_Pawn)
		{
			std::shared_ptr< Pawn > enemyPawn = std::dynamic_pointer_cast< Pawn > (enemyPiece);
			if (enemyPawn->Jump_Two_Squares())
			{
				valid = true;
			}
		}
	}
	return valid;
}


bool Pawn::Jump_Two_Squares() const
{
	return twoSquares;
}


bool Pawn::Attack_Range(Pos pos)
{
	return (Process_Attack(pos)) ? true : false;
}




