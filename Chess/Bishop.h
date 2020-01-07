#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(Pos, int, int);
	~Bishop();
	bool Is_Move_Valid(Pos, Board &);
	bool Attack_Range(Pos, Board &);
	bool Stalemate(Pos, Board &);
};

