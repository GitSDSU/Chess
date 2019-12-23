#include "stdafx.h"
#include "Player.h"
#include "Pawn.h"
#include "Board.h"
#include <iostream>
#include <cctype>


#define NUM_PAWNS	8


Player::Player(int t, Board &board)
{
	Pos pos;
	int col = 0;
	int row = 1;
	color = t;
	for (int i = 0; i < NUM_PIECES; i++)
	{
		pos.col = Starting_Position[color][col][i];
		pos.row = Starting_Position[color][row][i];
		///	Pawns
		if (i < NUM_PAWNS)
		{
			pieces.insert(std::make_pair(pos, PtrPiece(new Pawn(pos, color, _Pawn))));
		}
		else if (i == 8 || i == 9)
		{
			/// Knights
		}
		else if (i == 10 || i == 11)
		{
			/// Bishops
		}
		else if (i == 12 || i == 13)
		{
			/// Rooks
		}
		else if (i == 14)
		{
			/// Queen
		}
		else if (i == 15)
		{
			/// King
		}
	}
	Set_Pieces_On_Board(board);
}


Player::~Player()
{
}


void Player::Set_Pieces_On_Board(Board &board)
{
	for (auto i = pieces.begin(); i != pieces.end(); ++i)
	{
		board.Insert_Piece((*i).first, (*i).second);
	}
}


void Player::Choose_A_Piece()
{
	std::string msg[] = { "White To Move", "Black To Move" };
	char col, row;
	Pos pos;
	do
	{
		std::cout << msg[color] << std::endl;
		std::cout << "Choose Piece Location: ";
		std::cin >> col >> row;
		col = toupper(col);
		if (col < _A || col > _H || row < _1 || row > _8)
		{
			pos.col = 'Z';
			pos.row = '9';
		}
		else
		{
			pos.col = (int) col;
			pos.row = (int) row;
		}
	} while (pieces.count(pos));
	Choose_New_Square(pos);
}


void Player::Choose_New_Square(Pos piecePos)
{
	char col, row;
	Pos newSquare;
	do
	{
		std::cout << "Enter New Location: ";
		std::cin >> col >> row;
	} while (false);
}




