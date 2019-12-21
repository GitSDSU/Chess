#include "stdafx.h"
#include "Player.h"
#include "Pawn.h"
#include "Board.h"

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



