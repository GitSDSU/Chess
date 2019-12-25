#pragma once

#define	NUM_PLAYERS	2
#define NUM_SQUARES 64
#define NUM_PIECES	16
#define ESCAPE		27
#define SPACE		32


typedef enum { _A = 65, _B, _C, _D, _E, _F, _G, _H } Columns;
typedef enum { _1 = 49, _2, _3, _4, _5, _6, _7, _8 } Rows;
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
		if (this->row == other.row)
		{
			return this->col < other.col;
		}
		return this->row > other.row;
	}

	Pos const operator-(const Pos &second) const
	{
		Pos difference;
		difference.col = this->col - second.col;
		difference.row = this->row - second.row;
		return difference;
	}

	int Absolute(const int x) const
	{
		return (x < 0) ? x * -1 : x;
	}
};

