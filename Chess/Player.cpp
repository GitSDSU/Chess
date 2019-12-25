#include "stdafx.h"
#include "Player.h"
#include "Pawn.h"
#include "Board.h"
#include <iostream>
#include <cctype>
#include <conio.h>


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


Pos Player::Choose_A_Piece()
{
	std::string msg[] = { "[White] Choose Piece:", "[Black] Choose Piece:" };
	char col, row;
	Pos pos;
	do
	{
		std::cout << msg[color];
		col = _getch();
		col = toupper(col);
		std::cout << col;
		row = _getch();
		std::cout << row << std::endl;
		if (col == ESCAPE || row == ESCAPE)
		{
			std::cout << "Exit Game" << std::endl;
			exit(0);
		}
		else if (col < _A || col > _H || row < _1 || row > _8)
		{
			pos.col = 'Z';
			pos.row = '9';
		}
		else
		{
			pos.col = (int) col;
			pos.row = (int) row;
		}
	} while (!pieces.count(pos));
	return pos;
}


bool Player::Choose_New_Square(Pos piecePos, Board &board)
{
	char col, row;
	Pos newSquare;
	bool valid = false;
	PtrPiece playerPiece;
	bool reset = false;
	do
	{
		std::cout << "Choose Destination: ";
		col = _getch();
		col = toupper(col);
		std::cout << col;
		row = _getch();
		std::cout << row << std::endl;

		if (col == ESCAPE || row == ESCAPE)
		{
			std::cout << "Exit Game" << std::endl;
			exit(0);
		}
		else if (col == SPACE || row == SPACE)
		{
			std::cout << "Choose Different Piece" << std::endl;
			reset = true;
			valid = true;
		}
		else if (col < _A || col > _H || row < _1 || row > _8)
		{
			valid = false;
		}
		else
		{
			newSquare.col = col;
			newSquare.row = row;
			playerPiece = board.Return_Piece(piecePos);
			if (playerPiece->Is_Move_Valid(newSquare, board))
			{
				valid = true;
				board.Remove_Piece(piecePos);
				if (board.Is_Square_Empty(newSquare))
				{
					board.Insert_Piece(newSquare, playerPiece);
				}
				else
				{
					board.Remove_Piece(newSquare);
					board.Insert_Piece(newSquare, playerPiece);
				}
			}
			else
			{
				std::cout << "Illegal Move! Try Again." << std::endl; 
			}
		}
	} while (!valid);
	return reset;
}




