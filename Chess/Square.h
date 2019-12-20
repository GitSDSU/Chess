#pragma once

#include "Constants.h"
#include <memory>

class Piece;

typedef std::shared_ptr< Piece > PtrPiece;

class Square
{
public:
	Square(Pos);
	~Square();
	void Display_Square();
	void Insert_Piece(PtrPiece);
	void Remove_Piece();

private:
	Pos position;
	PtrPiece piece;
};

