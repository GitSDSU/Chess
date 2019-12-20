#include "stdafx.h"
#include "Square.h"
#include <iostream>
#include <string>


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
	std::cout << col[position.col-1] <<
		std::to_string(position.row);
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
	piece = std::move(p);
}


void Square::Remove_Piece()
{
	piece.reset();
}

