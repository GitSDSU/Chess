#include "stdafx.h"
#include "Square.h"
#include <iostream>
#include <string>

#define ASCII_A 65


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
	std::string col;
	switch (position.col)
	{
	case _A:
		col = "A";
		break;
	case _B:
		col = "B";
		break;
	case _C:
		col = "C";
		break;
	case _D:
		col = "D";
		break;
	case _E:
		col = "E";
		break;
	case _F:
		col = "F";
		break;
	case _G:
		col = "G";
		break;
	case _H:
		col = "H";
		break;
	default:
		break;
	}
	std::cout << col <<
		std::to_string(position.row);
	if (col[0] == 'H')
	{
		std::cout << std::endl;
	}
	else
	{
		std::cout << " ";
	}
}

