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
	Pos Choose_A_Piece();
	bool Choose_New_Square(Pos, Board &);
	void Update_Attacks(Board &);
	void Is_Stalemate(Board &);
	void Is_Checkmate(Board &);

private:
	int color;
	MapPiece pieces;
	void Set_Pieces_On_Board(Board &);
	void Update_Map_Keys(Pos, Pos);
};

