#include "stdafx.h"
#include <iostream>
#include "Board.h"
#include "Player.h"


int main()
{
	std::cout << "Start\n\n\n";

	Board board;
	Player white_player(White, board), black_player(Black, board);

	board.Display_Board();

	std::cin.get();

    return 0;
}

