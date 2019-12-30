#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King(Pos, int, int);
	~King();
	void Move() {  }
	bool Is_Move_Valid(Pos, Board &);
	bool Attack_Range(Pos);
private:
	bool King_Move(Pos);
	bool Castle(Pos, Board &);
	bool King_Attack(Pos, Board &);
	bool firstMove;
};

