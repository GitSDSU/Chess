#include "stdafx.h"
#include "King.h"
#include "Board.h"
#include "Rook.h"


King::King(Pos pos, int c, int t) : Piece(pos, c, t)
{
	moveCounter = 0;
}


King::~King()
{
}


bool King::Is_Move_Valid(Pos newPos, Board &board)
{
	bool valid = false;
	if (board.Is_Square_Empty(newPos))
	{
		if (King_Move(newPos, board))
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
		PtrPiece piece = board.Return_Piece(newPos);
		if (piece->Get_Color() != color)
		{
			if (King_Move(newPos, board))
			{
				board.Remove_Piece(newPos);
				valid = true;
			}
		}
	}
	if (valid)
	{
		moveCounter++;
	}
	return valid;
}


bool King::Attack_Range(Pos attackSquare, Board &board)
{
	bool valid = false;
	Pos displacement = attackSquare - position;
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


bool King::Is_Checkmate(Board &board)
{
	bool checkmate = false;

	if (board.Is_Square_Attacked(position, color))
	{
		checkmate = true;
		if (board.Square_Attackers(position, color) == 1)
		{
			/// Check if king can move
			/// Check if attacker can be captured
			/// Check if attack can be blocked
			if (Safe_Square(board))
			{
				checkmate = false;
			}
			else if (Capture_Attacker(board))
			{
				checkmate = false;
			}
			else if (Block_Attacker(board))
			{
				checkmate = false;
			}
		}
		else if (board.Square_Attackers(position, color) == 2)
		{
			/// Check if king can move
			if (Safe_Square(board))
			{
				checkmate = false;
			}
		}
	}
	return checkmate;
}


  /***************************************/
 /*******		Private			*********/
/***************************************/


bool King::King_Move(Pos newSquare, Board &board)
{
	bool valid = false;
	Pos displacement = newSquare - position;
	if (displacement.Absolute(displacement.col) == 1 && displacement.Absolute(displacement.row == 1) && !board.Is_Square_Attacked(newSquare, color))
	{
		valid = true;
	}
	else if (displacement.Absolute(displacement.col) == 1 && displacement.row == 0 && !board.Is_Square_Attacked(newSquare, color))
	{
		valid = true;
	}
	else if (displacement.col == 0 && displacement.Absolute(displacement.row == 1) && !board.Is_Square_Attacked(newSquare, color))
	{
		valid = true;
	}
	return valid;
}


bool King::Castle(Pos emptySquare, Board &board)
{
	bool valid = false;
	Pos displacement = emptySquare - position;
	if ((emptySquare.col == _C || emptySquare.col == _G) && First_Move() &&
		((emptySquare.row == _1 && color == Team::White) || (emptySquare.row == _8 && color == Team::Black)))
	{
		Pos tempRookPos = emptySquare;
		if (board.Is_Square_Empty(emptySquare) && !board.Is_Square_Attacked(tempRookPos, color))
		{
			tempRookPos.col = (emptySquare.col == _C) ? _D : _F;
			Pos tempKnightPos = emptySquare;
			tempKnightPos.col = (emptySquare.col == _C) ? _B : _G;
			if (board.Is_Square_Empty(tempRookPos) && !board.Is_Square_Attacked(tempRookPos, color) && board.Is_Square_Empty(tempKnightPos))
			{
				tempRookPos.col = (emptySquare.col == _C) ? _A : _H;
				if (!board.Is_Square_Empty(tempRookPos))
				{
					PtrPiece piece = board.Return_Piece(tempRookPos);
					if (piece->Get_Type() == Type::_Rook)
					{
						std::shared_ptr< Rook > rook = std::dynamic_pointer_cast< Rook > (piece);
						if (rook->First_Move() && rook->Get_Color() == color)
						{
							valid = true;
							Pos rookPos = emptySquare;
							rookPos.col += (emptySquare.col == _C) ? 1 : -1;
							board.Remove_Piece(rook->Get_Pos());
							rook->Set_Pos(rookPos);
							board.Insert_Piece(rookPos, rook);
						}
					}
				}
			}
		}
	}
	return valid;
}


bool King::Safe_Square(Board &board)
{
	bool safe = false;
	int x = position.col;
	int y = position.row;
	int posX[] = { x + 0, x + 1, x + 1, x + 1, x + 0, x - 1, x - 1, x - 1 };
	int posY[] = { y + 1, y + 1, y + 0, y - 1, y - 1, y - 1, y + 0, y + 1 };
	Pos posTemp;

	for (int i = 0; i < sizeof(posX) / sizeof(int); i++)
	{
		if (posX[i] >= _A && posX[i] <= _H && posY[i] >= _1 && posY[i] <= _8)
		{
			posTemp.col = posX[i];
			posTemp.row = posY[i];
			if (board.Square_Attackers(posTemp, color) == 0 && board.Is_Square_Empty(posTemp))
			{
				if (board.Is_Square_Empty(posTemp))
				{
					safe = true;
				}
				else
				{
					PtrPiece enemyPiece = board.Return_Piece(posTemp);
					if (enemyPiece->Get_Color() != color)
					{
						safe = true;
					}
				}
			}
		}
	}

	return safe;
}


bool King::Capture_Attacker(Board &board)
{
	bool capture = false;
	PtrPiece attackingPiece = board.Return_Attacker(position, color);
	if (board.Is_Square_Attacked(attackingPiece->Get_Pos(), attackingPiece->Get_Color()))
	{
		capture = true;
	}
	return capture;
}


bool King::Block_Attacker(Board &board)
{
	/// Assume there's only one enemy attacker
	bool block = false;
	PtrPiece attackingPiece = board.Return_Attacker(position, color);
	Pos displacement = attackingPiece->Get_Pos() - position;
	int col = displacement.col;
	int row = displacement.row;
	switch (attackingPiece->Get_Type())
	{
	case _Pawn:
		/// Cannot be blocked
	{

	}
		break;
	case _Knight:
		/// Cannot be blocked
	{

	}
		break;
	case _Bishop:
	{
		Pos tempBishopMove;
		for (int i = 1; i < displacement.Absolute(col); i++)
		{
			tempBishopMove.col = (displacement.col > 0) ? position.col - i : position.col + i;
			tempBishopMove.row = (displacement.row > 0) ? position.row - i : position.row + i;
			if (board.Is_Square_Attacked(tempBishopMove, attackingPiece->Get_Color()))
			{
				block = true;
				break;
			}
		}
	}
		break;
	case _Rook:
	{
		Pos tempRookMove;
		int range = (col != 0) ? col : row;
		for (int i = 1; i < displacement.Absolute(range); i++)
		{
			if (col != 0)
			{
				tempRookMove.col = (displacement.col > 0) ? position.col - i : position.col + i;
			}
			else
			{
				tempRookMove.row = (displacement.row > 0) ? position.row - i : position.row + i;
			}
			if (board.Is_Square_Attacked(tempRookMove, attackingPiece->Get_Color()))
			{
				block = true;
				break;
			}
		}
	}
		break;
	case _Queen:
	{
		int typeMove = (displacement.Absolute(col) == displacement.Absolute(row)) ? _Bishop : _Rook;
		if (typeMove == _Bishop)
		{
			Pos tempBishopMove;
			for (int i = 1; i < displacement.Absolute(col); i++)
			{
				tempBishopMove.col = (displacement.col > 0) ? position.col - i : position.col + i;
				tempBishopMove.row = (displacement.row > 0) ? position.row - i : position.row + i;
				if (board.Is_Square_Attacked(tempBishopMove, attackingPiece->Get_Color()))
				{
					block = true;
					break;
				}
			}
		}
		else
		{
			Pos tempRookMove;
			int range = (col != 0) ? col : row;
			for (int i = 1; i < displacement.Absolute(range); i++)
			{
				if (col != 0)
				{
					tempRookMove.col = (displacement.col > 0) ? position.col - i : position.col + i;
				}
				else
				{
					tempRookMove.row = (displacement.row > 0) ? position.row - i : position.row + i;
				}
				if (board.Is_Square_Attacked(tempRookMove, attackingPiece->Get_Color()))
				{
					block = true;
					break;
				}
			}
		}
	}
		break;
	case _King:
		/// Cannot be blocked
	{

	}
		break;
	default:
	{
		/* Error: something went wrong */
		exit(0);
	}
		break;
	}

	return block;
}


bool King::Stalemate(Pos newPos, Board &board)
{
	bool valid = false;
	Pos displacement = newPos - position;
	if (displacement.Absolute(displacement.col) == 1 && displacement.Absolute(displacement.row == 1) && !board.Is_Square_Attacked(newPos, color))
	{
		valid = true;
	}
	else if (displacement.Absolute(displacement.col) == 1 && displacement.row == 0 && !board.Is_Square_Attacked(newPos, color))
	{
		valid = true;
	}
	else if (displacement.col == 0 && displacement.Absolute(displacement.row == 1) && !board.Is_Square_Attacked(newPos, color))
	{
		valid = true;
	}
	return valid;
}


bool King::First_Move() const
{
	return (moveCounter > 0) ? false : true;
}









