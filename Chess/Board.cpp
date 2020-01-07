#include "stdafx.h"
#include "Board.h"
#include "Square.h"
#include "Piece.h"


Board::Board()
{
	Pos pos;

	for (int row = _1; row <= _8; row++)
	{
		for (int col = _A; col <= _H; col++)
		{
			pos.col = col;
			pos.row = row;
			board.insert(std::make_pair(pos, PtrSquare(new Square(pos))));
		}
	}
}


Board::~Board()
{
}


void Board::Display_Board()
{
	for (auto i = board.begin(); i != board.end(); ++i)
	{
		(i)->second->Display_Square();
	}
}


void Board::Insert_Piece(Pos pos, PtrPiece piece)
{
	board[pos]->Insert_Piece(piece);
}


void Board::Remove_Piece(Pos pos)
{
	board[pos]->Remove_Piece();
}


bool Board::Is_Square_Empty(Pos pos)
{
	return board[pos]->Is_Square_Empty();
}


PtrPiece Board::Return_Piece(Pos pos)
{
	return board[pos]->Return_Piece();
}


void Board::Update_Attacks(Pos attackSquare, PtrPiece piece)
{
	board[attackSquare]->Increase_Attack(piece);
}


void Board::Reset_Attacks()
{
	for (const auto &square : board)
	{
		square.second->Reset_Attack();
	}
}


bool Board::Is_Square_Attacked(Pos pos, int team)
{
	return board[pos]->Is_Square_Attacked(team);
}


int Board::Square_Attackers(Pos pos, int team)
{
	return board[pos]->Num_Attackers(team);
}


PtrPiece Board::Return_Attacker(Pos pos, int team)
{
	return board[pos]->Return_Attacker(team);
}















