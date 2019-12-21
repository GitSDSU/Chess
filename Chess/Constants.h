#pragma once

#define	NUM_PLAYERS	2
#define NUM_SQUARES 64
#define NUM_PIECES	16

typedef enum { _A = 1, _B, _C, _D, _E, _F, _G, _H } Columns;
typedef enum { _1 = 1, _2, _3, _4, _5, _6, _7, _8 } Rows;
typedef enum { White, Black } Team;
typedef enum { _Pawn, _Knight, _Bishop, _Rook, _Queen, _King, _Total = 6 } Type;

const int Starting_Position[NUM_PLAYERS][NUM_PLAYERS][NUM_PIECES] =
{ 
	/// White
	{
		/// Columns
		{ _A, _B, _C, _D, _E, _F, _G, _H, _B, _G, _C, _F, _A, _H, _D, _E },
		/// Rows
		{ _2, _2, _2, _2, _2, _2, _2, _2, _1, _1, _1, _1, _1, _1, _1, _1 }
	},
	/// Black
	{
		/// Columns
		{ _A, _B, _C, _D, _E, _F, _G, _H, _B, _G, _C, _F, _A, _H, _D, _E },
		/// Rows
		{ _7, _7, _7, _7, _7, _7, _7, _7, _8, _8, _8, _8, _8, _8, _8, _8 }
	}
};

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

