#pragma once

#include <memory>
#include <map>
#include "Constants.h"
#include <string>

class Piece;
class Board;

typedef std::shared_ptr< Piece > PtrPiece;
typedef std::map< Pos, PtrPiece > MapPiece;


class Player
{
public:
	Player(int, Board &);
	~Player();
	void Choose_A_Piece();
	void Choose_New_Square(Pos);

private:
	int color;
	MapPiece pieces;
	void Set_Pieces_On_Board(Board &);
};

