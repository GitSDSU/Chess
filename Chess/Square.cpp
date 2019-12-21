#include "stdafx.h"
#include "Square.h"
#include <iostream>
#include <string>
#include "Piece.h"


Square::Square(Pos p)
{
	position.col = p.col;
	position.row = p.row;
}


Square::~Square()
{
}


void Square::Display_Square()
{
	std::string col[] = { "A", "B", "C", "D", "E", "F", "G", "H" };
	if (Is_Square_Empty())
	{
		std::cout << col[position.col - 1] <<
			std::to_string(position.row);
	}
	else
	{
		const std::string symbol[NUM_PLAYERS][Type::_Total] = 
			{ 
				{ "wP", "wN", "wB", "wR", "wQ", "wK" },
				{ "bP", "bN", "bB", "bR", "bQ", "bK" }
			};
		std::cout << symbol[piece->Get_Color()][piece->Get_Type()];
	}
	if (col[position.col - 1] == "H")
	{
		std::cout << std::endl;
	}
	else
	{
		std::cout << " ";
	}
}


void Square::Insert_Piece(PtrPiece p)
{
	piece.reset();
	piece = std::move(p);
}


void Square::Remove_Piece()
{
	piece.reset();
}


bool Square::Is_Square_Empty()
{
	return (piece == nullptr) ? true : false;
}


