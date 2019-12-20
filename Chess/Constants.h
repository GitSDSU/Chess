#pragma once

#define	NUM_PLAYERS	2
#define NUM_SQUARES 64

typedef enum { _A = 1, _B, _C, _D, _E, _F, _G, _H } Columns;
typedef enum { _1 = 1, _2, _3, _4, _5, _6, _7, _8 } Rows;

struct Pos
{
	int col;
	int row;

	bool const operator<(const Pos &other) const
	{
		if (row == other.row)
		{
			return col < other.col;
		}
		return row > other.row;
	}
};

