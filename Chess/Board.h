#pragma once

#include <map>
#include <memory>
#include "Constants.h"

class Square;
class Piece;

typedef std::shared_ptr< Piece > PtrPiece;
typedef std::unique_ptr<Square> PtrSquare;
typedef std::map<Pos, PtrSquare > MapSquare;

class Board
{
public:
	Board();
	~Board();
	void Display_Board();
	void Insert_Piece(Pos, PtrPiece);
	void Remove_Piece(Pos);
	bool Is_Square_Empty(Pos);
	PtrPiece Return_Piece(Pos);
	void Update_Attacks(Pos, int);
	void Reset_Attacks();

private:
	MapSquare board;
};

