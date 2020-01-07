#include "stdafx.h"
#include "Piece.h"


Piece::Piece(Pos p, int c, int t)
{
	position = p;
	color = c;
	type = t;
	captured = false;
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


Pos Piece::Get_Pos() const
{
	return position;
}


bool Piece::Is_Captured() const
{
	return captured;
}


void Piece::Capture()
{
	captured = true;
}


void Piece::Set_Pos(const Pos nPos)
{
	position = nPos;
}











