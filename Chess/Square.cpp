#include "stdafx.h"
#include "Square.h"
#include <iostream>
#include <string>
#include "Piece.h"


Square::Square(Pos p)
{
	position.col = p.col;
	position.row = p.row;
}


Square::~Square()
{
}


void Square::Display_Square()
{
	std::string col[] = { "A", "B", "C", "D", "E", "F", "G", "H" };
	std::string row[] = { "1", "2", "3", "4", "5", "6", "7", "8" };
	if (Is_Square_Empty())
	{
		std::cout << col[position.col - _A] << row[position.row - _1];
	}
	else
	{
		const std::string symbol[NUM_PLAYERS][Type::_Total] = 
			{ 
				{ "wP", "wN", "wB", "wR", "wQ", "wK" },
				{ "bP", "bN", "bB", "bR", "bQ", "bK" }
			};
		std::cout << symbol[piece->Get_Color()][piece->Get_Type()];
	}
	if (col[position.col - _A] == "H")
	{
		std::cout << std::endl;
	}
	else
	{
		std::cout << " ";
	}
}


void Square::Insert_Piece(PtrPiece p)
{
	piece.reset();
	piece = p;
}


void Square::Remove_Piece()
{
	piece.reset();
}


bool Square::Is_Square_Empty()
{
	return (piece == nullptr) ? true : false;
}


PtrPiece Square::Return_Piece()
{
	return piece;
}


void Square::Reset_Attack()
{
	attackers.clear();
}


void Square::Increase_Attack(PtrPiece attackingPiece)
{
	attackers.insert(std::make_pair(attackingPiece->Get_Pos(), attackingPiece));
}


bool Square::Is_Square_Attacked(int team)
{
	bool attacked = false;
	for (auto const &x : attackers)
	{
		if (x.second->Get_Color() != team)
		{
			attacked = true;
			break;
		}
	}
	return attacked;
}


int Square::Num_Attackers(int team)
{
	int counter = 0;
	for (auto const &x : attackers)
	{
		if (x.second->Get_Color() != team)
		{
			counter++;
		}
	}
	return counter;
}


PtrPiece Square::Return_Attacker(int team)
{
	/// Assumes there's only one enemy attacker
	PtrPiece attackerPiece;
	for (const auto &x : attackers)
	{
		if (x.second->Get_Color() != team)
		{
			attackerPiece = x.second;
			break;
		}
	}
	return attackerPiece;
}
















