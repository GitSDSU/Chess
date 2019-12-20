#pragma once

#include <map>
#include <memory>
#include "Constants.h"

class Square;

typedef std::unique_ptr<Square> PtrSquare;
typedef std::map<Pos, PtrSquare > MapSquare;

class Board
{
public:
	Board();
	~Board();
	void Display_Board();

private:
	MapSquare board;
};

