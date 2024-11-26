#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <stack>
#include "Point.hpp"
class Board {
public:
    int n = 0, m = 0; // n is the number of rows, m is the number of columns.
    std::vector<std::vector<int>> mat;
    std::stack<std::pair<DPoint, int>> records;
public:
    Board(int N = 0, int M = 0);
    void print_in_console();
    void backtrack();
};

class GomokuBoard : public Board {
public:
    int sum_black = 0, sum_white = 0;
public:
    GomokuBoard(int N = 15, int M = 15);// -1 nothing , 0 black , 1 white.
    int place (DPoint pos, int color = 0); // -1 illegal, 0 game continue, 1 game end.
};

#endif
