#include "stdafx.h"
#include "Pawn.h"
#include "Board.h"


Pawn::Pawn(Pos pos, int c, int t) : Piece(pos, c, t)
{
	firstMove = true;
	moveCounter = 0;
}


Pawn::~Pawn()
{
}


bool Pawn::Is_Move_Valid(Pos newPos, Board &board)
{
	bool valid_move = false;
	PtrPiece temporary_piece;
	if (board.Is_Square_Empty(newPos))
	{
		if (Enpassant(newPos, board))
		{
			valid_move = true;
		}
		else if (Process_Move(newPos, board))
		{
			valid_move = true;
		}
	}
	else
	{
		temporary_piece = board.Return_Piece(newPos);
		if (temporary_piece->Get_Color() != color)
		{
			if (Process_Attack(newPos, board))
			{
				valid_move = true;
			}
		}
	}
	if (valid_move)
	{
		moveCounter++;
		if (moveCounter > 1 && firstMove)
		{
			firstMove = false;
		}
	}
	return valid_move;
}


bool Pawn::Process_Move(Pos emptySquare, Board &board)
{
	bool valid = false;
	Pos displacement = emptySquare - position;
	Pos tempPawnMove = position;
	if (color == Team::White)
	{
		tempPawnMove.row += 1;
		if (displacement.col == 0 && displacement.row == 1)
		{
			valid = true;
		}
		else if (displacement.col == 0 && displacement.row == 2 && position.row == _2 && board.Is_Square_Empty(tempPawnMove))
		{
			valid = true;
		}
	}
	else
	{
		tempPawnMove.row -= 1;
		if (displacement.col == 0 && displacement.row == -1)
		{
			valid = true;
		}
		else if (displacement.col == 0 && displacement.row == -2 && position.row == _7 && board.Is_Square_Empty(tempPawnMove))
		{
			valid = true;
		}
	}
	return valid;
}


bool Pawn::Process_Attack(Pos enemyPos, Board &board)
{
	bool valid = false;
	Pos displacement = enemyPos - position;
	if (color == Team::White)
	{
		if (displacement.Absolute(displacement.col) == 1 && displacement.row == 1)
		{
			PtrPiece enemyPiece = board.Return_Piece(enemyPos);
			enemyPiece->Capture();
			board.Remove_Piece(enemyPos);
			valid = true;
		}
	}
	else
	{
		if (displacement.Absolute(displacement.col) == 1 && displacement.row == -1)
		{
			PtrPiece enemyPiece = board.Return_Piece(enemyPos);
			enemyPiece->Capture();
			board.Remove_Piece(enemyPos);
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
			if (enemyPawn->First_Move())
			{
				board.Remove_Piece(enemyPawn->Get_Pos());
				valid = true;
			}
		}
	}
	return valid;
}


bool Pawn::First_Move() const
{
	return firstMove;
}


bool Pawn::Attack_Range(Pos attackSquare, Board &board)
{
	bool valid = false;
	Pos displacement = attackSquare - position;
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


bool Pawn::Stalemate(Pos newPos, Board &board)
{
	bool valid = false;
	if (board.Is_Square_Empty(newPos))
	{
		/// Regular move
		Pos displacement = newPos - position;
		Pos tempPawnMove = position;
		if (color == Team::White)
		{
			tempPawnMove.row += 1;
			if (displacement.col == 0 && displacement.row == 1)
			{
				valid = true;
			}
			else if (displacement.col == 0 && displacement.row == 2 && position.row == _2 && board.Is_Square_Empty(tempPawnMove))
			{
				valid = true;
			}
		}
		else
		{
			tempPawnMove.row -= 1;
			if (displacement.col == 0 && displacement.row == -1)
			{
				valid = true;
			}
			else if (displacement.col == 0 && displacement.row == -2 && position.row == _7 && board.Is_Square_Empty(tempPawnMove))
			{
				valid = true;
			}
		}
		/// Enpassant
		PtrPiece enemyPiece;
		Pos enemySquare;
		enemySquare.col = newPos.col;
		enemySquare.row = (color == Team::White) ? newPos.row - 1 : newPos.row + 1;
		if (enemySquare.col >= _A && enemySquare.col <= _H && enemySquare.row >= _1 && enemySquare.row <= _8)
		{
			if (!board.Is_Square_Empty(enemySquare))
			{
				enemyPiece = board.Return_Piece(enemySquare);
				if (enemyPiece->Get_Color() != color && enemyPiece->Get_Type() == Type::_Pawn)
				{
					std::shared_ptr< Pawn > enemyPawn = std::dynamic_pointer_cast< Pawn > (enemyPiece);
					if (enemyPawn->First_Move())
					{
						valid = true;
					}
				}
			}
		}
	}
	else
	{
		/// Capture
		PtrPiece enemyPiece = board.Return_Piece(newPos);
		if (enemyPiece->Get_Color() != color)
		{
			Pos displacement = newPos - position;
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
		}
	}
	return valid;
}













