#include <iostream>
#include "Board.hpp"
#include "Gomoku_Hzy001.hpp"
int main() {
	std::cout << "Hello World!" << std::endl;
	GomokuBoard board(15,15);
	Hzy001 AI(board);
	bool game_run = 1;
	int round = 0;
	while (game_run) {
		DPoint pos;
		if (round % 2 == 1) { // white move.
			while (1) {
				std::cin >> pos.x >> pos.y;
				if (board.mat[pos.x][pos.y] == -1) {
					break;
				}
			}
		}
		else { // black move.
			pos = AI.place_test();
		}
		int v = board.place(pos,round % 2);
		std::cout << "Round " << round << std::endl;
		board.print_in_console();
		std::cout << std::endl;
		if (v == 0) {
		}
		else if (v == 1) {
			if (round % 2 == 1) {
				std::cout << "White Win!" << std::endl;
				game_run = 0;
			}
			else {
				std::cout << "Black Win!" << std::endl;
				game_run = 0;
			}
			break;
		}
		else {
		}
		round++;
	}
	return 0;
}