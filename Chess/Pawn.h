#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	Pawn(Pos, int, int);
	~Pawn();
	void Move() { }
};

