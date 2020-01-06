#pragma once

#include "Constants.h"
#include <memory>
#include <map>


class Piece;

typedef std::shared_ptr< Piece > PtrPiece;
typedef std::map< Pos, PtrPiece > MapPiece;

class Square
{
public:
	Square(Pos);
	~Square();
	void Display_Square();
	void Insert_Piece(PtrPiece);
	void Remove_Piece();
	bool Is_Square_Empty();
	PtrPiece Return_Piece();
	void Reset_Attack();
	void Increase_Attack(PtrPiece);
	bool Is_Square_Attacked(int);
	int Num_Attackers(int);
	PtrPiece Return_Attacker(int);

private:
	Pos position;
	PtrPiece piece;
	MapPiece attackers;
};

