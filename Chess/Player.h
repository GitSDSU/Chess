#pragma once

#include <memory>
#include <map>
#include "Constants.h"

class Piece;
class Board;

typedef std::shared_ptr< Piece > PtrPiece;
typedef std::map< Pos, PtrPiece > MapPiece;


class Player
{
public:
	Player(int, Board &);
	~Player();

private:
	int color;
	MapPiece pieces;
	void Set_Pieces_On_Board(Board &);
};

