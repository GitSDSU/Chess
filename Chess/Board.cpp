#include "stdafx.h"
#include "Board.h"
#include "Square.h"


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
	board[pos]->Insert_Piece(std::move(piece));
}


void Board::Remove_Piece(Pos pos)
{
	board[pos]->Remove_Piece();
}


