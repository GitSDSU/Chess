#include "stdafx.h"
#include <iostream>
#include "Board.h"
#include "Player.h"
#include <conio.h>


void Start_Menu();
void Test();


int main()
{
	Test();
	Start_Menu();

	char  input;
	input = _getch();
	switch (input)
	{
		case ESCAPE:
			std::cout << "Exit Game" << std::endl;
			exit(0);
		default:
			break;
	}
	Board board;
	Player white_player(White, board), black_player(Black, board);

	board.Display_Board();
	
	while (1)
	{
		/// White's Turn
		while (white_player.Choose_New_Square(white_player.Choose_A_Piece(), board));
		board.Display_Board();
		board.Reset_Attacks();
		white_player.Update_Attacks(board);
		black_player.Update_Attacks(board);
		black_player.Is_Checkmate(board);
		black_player.Is_Stalemate(board);
		/// Black's Turn
		while (black_player.Choose_New_Square(black_player.Choose_A_Piece(), board));
		board.Display_Board();
		board.Reset_Attacks();
		white_player.Update_Attacks(board);
		black_player.Update_Attacks(board);
		white_player.Is_Checkmate(board);
		white_player.Is_Stalemate(board);
	}
	_getch();

    return 0;
}


void Start_Menu()
{
	std::cout << "[ESC]	- Exit Game" << std::endl;
	std::cout << "[SPACE]	- Choose Different Piece" << std::endl;
	std::cout << "[1]	- Versus CPU" << std::endl;
	std::cout << "[2]	- Two Player Game" << std::endl;
	std::cout << "\n\n" << std::endl;
}


void Test()
{
	
}












