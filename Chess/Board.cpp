#include "stdafx.h"
#include "Board.h"
#include "Square.h"
#include "Piece.h"
#include <iostream>
#include <string>
#include <vector>


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
	std::string space1(1, ' ');
	std::string space2(2, ' ');
	std::string space3(3, ' ');
	std::string space5(5, ' ');
	std::string leftMargin(10, ' ');
	std::string leftSide(leftMargin.size() - 2, ' ');
	std::vector< std::string > columns = { "A", "B", "C", "D", "E", "F", "G", "H" };
	std::vector< std::string > rows = { "8", "7", "6", "5", "4", "3", "2", "1" };
	std::string border(49, '#');
	std::string hashtag(1, '#');
	std::cout << leftMargin;
	for (int i = 0; i < columns.size(); i++)
	{
		std::cout << space3 << columns[i] << space2;
	}
	std::cout << std::endl;
	std::cout << leftMargin << border << std::endl;
	int j = 0;
	Pos pos;
	pos.col = _A;
	pos.row = _8;
	for (int i = 1; i <= 32; i++)
	{
		if (i == 2 || i == 6 || i == 10 || i == 14 || i == 18 || i == 22 || i == 26 || i == 30)
		{

			std::cout << leftSide << rows[j] << space1 << hashtag;
			for (int k = 1; k <= 8; k++)
			{
				std::cout << space2;
				board[pos]->Display_Square();
				std::cout << space2 << hashtag;
				pos.col += 1;
			}
			std::cout <<  std::endl;
			j++;
		}
		else if (i % 4 == 0)
		{
			std::cout << leftMargin << border << std::endl;
			pos.col = _A;
			pos.row -= 1;
		}
		else
		{
			std::cout << leftMargin << hashtag << space5 << hashtag << space5 << hashtag << space5 << hashtag << space5 <<
				hashtag << space5 << hashtag << space5 << hashtag << space5 << hashtag << space5 << hashtag << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
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















