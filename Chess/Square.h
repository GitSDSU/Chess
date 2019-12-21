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
	bool Is_Square_Empty();

private:
	Pos position;
	PtrPiece piece;
};

