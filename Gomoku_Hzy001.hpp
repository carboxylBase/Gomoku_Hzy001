#ifndef GOMOKU_HZY001_HPP
#define GOMOKU_HZY001_HPP

#include "Board.hpp"
#include "Point.hpp"
class Hzy001 {
public:
	GomokuBoard& board;
public:
	Hzy001(GomokuBoard& a) : board(a){}
	DPoint place_test();
	std::pair<DPoint,int> place_min_max_dfs(int dep = 0);
};

#endif