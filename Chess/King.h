#pragma once
#include "Piece.h"
class Rook;
class King :
	public Piece
{
public:
	King(Pos, int, int);
	~King();
	bool Is_Move_Valid(Pos, Board &);
	bool Attack_Range(Pos, Board &);
	bool Is_Checkmate(Board &);
	bool Stalemate(Pos, Board &);
private:
	bool King_Move(Pos, Board &);
	bool Castle(Pos, Board &);
	bool Safe_Square(Board &);
	bool Capture_Attacker(Board &);
	bool Block_Attacker(Board &);
	bool First_Move() const;
	int moveCounter;
};

