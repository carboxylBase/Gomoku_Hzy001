#include "Gomoku_Hzy001.hpp"
#include <time.h>
#include <iostream>
#include <algorithm>
DPoint Hzy001::place_test() {
	while (1) {
		int x = rand() % board.n;
		int y = rand() % board.m;
		if (board.mat[x][y] == -1) {
			return DPoint(x, y);
		}
	}
}

DPoint V[8] = { {0,1}, {1,1},{1,-1},{1,0},{0,-1} ,{-1,-1},{-1,1},{-1,0} };
int score[6] = {0,5,10,20,50,1000};
const int WIDTH = 5;
const int DEPTH = 6;

std::pair<DPoint,int> Hzy001::place_min_max_dfs(int dep) {
	int color;
	if (board.sum_white == board.sum_black) {
		color = 0;
	}
	else {
		color = 1;
	}
	std::vector < std::pair<DPoint,int> > q;
	auto cal = [&](int x,int y) {
		return 0;
	};
	auto cmp = [&](std::pair<DPoint, int>& A, std::pair<DPoint, int>& B) {
		return A.second > B.second;
	};
	for (int i = 0; i < board.n ; i++) {
		for (int j = 0; j < board.m ; j++) {
			q.push_back({DPoint(i,j),cal(i,j)});
		}
	}
	sort(q.begin(),q.end(),cmp);
	if (dep == DEPTH) {
		return q[0];
	}
	else {
		while (q.size() > WIDTH) {
			q.pop_back();
		}
		if (q[0].second > 5000) {
			return q[0];
		}
		int max_score = -5000;
		for (int i = 0; i < WIDTH; i++) {
			board.place(q[i].first,color);
			int score = place_min_max_dfs(dep+1).second;
			board.backtrack();
			max_score = std::max(max_score, score);
			q[i].second -= max_score;
		}
		sort(q.begin(),q.end(),cmp);
		return q[0];
	}
}