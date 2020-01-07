#include "stdafx.h"
#include "Player.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
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
			pieces.insert(std::make_pair(pos, PtrPiece(new Knight(pos, color, _Knight))));
		}
		else if (i == 10 || i == 11)
		{
			/// Bishops
			pieces.insert(std::make_pair(pos, PtrPiece(new Bishop(pos, color, _Bishop))));
		}
		else if (i == 12 || i == 13)
		{
			/// Rooks
			pieces.insert(std::make_pair(pos, PtrPiece(new Rook(pos, color, _Rook))));
		}
		else if (i == 14)
		{
			/// Queen
			pieces.insert(std::make_pair(pos, PtrPiece(new Queen(pos, color, _Queen))));
		}
		else if (i == 15)
		{
			pieces.insert(std::make_pair(pos, PtrPiece(new King(pos, color, _King))));
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
	std::string msg[] = { "[White] Choose Piece: ", "[Black] Choose Piece: " };
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
	std::string msg[] = { "[White] Choose Destination: ", "[Black] Choose Destination: " };
	char col, row;
	Pos newSquare;
	bool valid = false;
	PtrPiece playerPiece;
	bool reset = false;
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
				playerPiece->Set_Pos(newSquare);
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
	if (!reset)
	{
		Update_Map_Keys(piecePos, newSquare);
	}
	return reset;
}


void Player::Update_Attacks(Board &board)
{
	Pos pos;
	for (auto piece = pieces.cbegin(); piece != pieces.cend(); /* no increment */)
	{
		if (piece->second->Is_Captured())
		{
			pieces.erase(piece++);
		}
		else
		{
			++piece;
		}
	}
	for (auto piece = pieces.begin(); piece != pieces.end(); ++piece)
	{
		for (int col = _A; col <= _H; col++)
		{
			pos.col = col;
			for (int row = _1; row <= _8; row++)
			{
				pos.row = row;
				if ((*piece).second->Attack_Range(pos, board))
				{
					board.Update_Attacks(pos, (*piece).second);
				}
			}
		}
	}
}


void Player::Is_Stalemate(Board &board)
{
	Pos pos;
	bool validMove = false;
	for (const auto &piece : pieces)
	{
		for (int col = _A; col <= _H; col++)
		{
			pos.col = col;
			for (int row = _1; row <= _8; row++)
			{
				pos.row = row;
				if (piece.second->Stalemate(pos, board))
				{
					validMove = true;
					break;
				}
			}
			if (validMove)
			{
				break;
			}
		}
		if (validMove)
		{ 
			break;
		}
	}
	if (!validMove)
	{
		std::cout << "Stalemate..." << std::endl;
		exit(0);
	}
}


void Player::Update_Map_Keys(Pos oldKey, Pos newKey)
{
	typename MapPiece::iterator begin(pieces.find(oldKey));
	for (;;)
	{
		if (begin != pieces.end())
		{
			pieces.insert(typename MapPiece::value_type(newKey, begin->second));
			pieces.erase(begin);
			begin = pieces.find(oldKey);
		}
		else
		{
			break;
		}
	}
}


void Player::Is_Checkmate(Board &board)
{
	for (const auto &piece : pieces)
	{
		if (piece.second->Get_Type() == Type::_King)
		{
			std::shared_ptr< King > king = std::dynamic_pointer_cast< King > (piece.second);
			if (king->Is_Checkmate(board))
			{
				std::string msg[] = { "Black Player Wins!", "White Player Wins!" };
				std::cout << msg[color] << std::endl;
				exit(0);
			}
			else
			{
				return;
			}
		}
	}
}






















