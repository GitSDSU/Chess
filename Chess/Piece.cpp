#include "stdafx.h"
#include "Piece.h"


Piece::Piece(Pos p, int c, int t)
{
	position = p;
	color = c;
	type = t;
}


Piece::~Piece()
{
}


int Piece::Get_Color() const
{
	return color;
}


int Piece::Get_Type() const
{
	return type;
}
