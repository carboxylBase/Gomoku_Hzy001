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

/*
	0 1
	1 11
	2 111
	3 1111
	4 12
	5 112
	6 1112
	7 01
	8 011
	9 012
	10 0112
	11 01112
*/
DPoint V[8] = { {0,1}, {1,1},{1,-1},{1,0},{0,-1} ,{-1,-1},{-1,1},{-1,0} };
int score[14] = {10,20,4000,5000,5,15,30,5,20,1,15,30};
const int WIDTH = 4;
const int DEPTH = 10;

std::pair<DPoint,int> Hzy001::place_min_max_dfs(int dep) {
	int color;
	if (board.sum_white == board.sum_black) {
		color = 0;
	}
	else {
		color = 1;
	}
	// First hand in the middle.
	if (board.sum_black == 0 && board.sum_white == 0) {
		std::cout << "ok" << std::endl;
		return { DPoint(7,7),0 };
	}
	std::vector < std::pair<DPoint,int> > q;
	auto cal = [&](int x,int y) {
		#define LEGAL (u >= 0 && u < board.n && v >= 0 && v < board.m)
		int sum = 0;
		for (int i = 0; i < 8; i++) {
			int u = x + V[i].x, v = y + V[i].y;
			if (!LEGAL) {
				continue;
			}
			int color, cnt = 1;
			if (board.mat[u][v] == -1) {
				u += V[i].x, v += V[i].y;
				if (!LEGAL) {
					continue;
				}
				if (board.mat[u][v] == -1) {
					continue;
				}
				else {
					color = board.mat[u][v];
					for (int j = 0; j < 3; j++) {
						u += V[i].x, v += V[i].y;
						if (!LEGAL) {
							if (cnt == 1) {
								sum += score[9];
							}
							else if (cnt == 2) {
								sum += score[10];
							}
							else if (cnt == 3) {
								sum += score[11];
							}
							else {
								sum += score[3];
							}
							break;
						}
						if (board.mat[u][v] == -1) {
							if (cnt == 1) {
								sum += score[7];
							}
							else {
								sum += score[8];
							}
							break;
						}
						else if (board.mat[u][v] == color) {
							cnt++;
							if (cnt == 3) {
								sum += score[11];
								break;
							}
						}
						else {
							if (cnt == 1) {
								sum += score[9];
							}
							else if (cnt == 2) {
								sum += score[10];
							}
							else if (cnt == 3) {
								sum += score[11];
							}
							break;
						}
					}
				}
			}
			else {
				color = board.mat[u][v];
				for (int j = 0; j < 4; j++) {
					u += V[i].x, v += V[i].y;
					if (!LEGAL) {
						if (cnt == 1) {
							sum += score[4];
						}
						else if (cnt == 2) {
							sum += score[5];
						}
						else if (cnt == 3) {
							sum += score[6];
						}
						else {
							sum += score[3];
						}
						break;
					}
					if (board.mat[u][v] == -1) {
						if (cnt == 1) {
							sum += score[0];
						}
						else if (cnt == 2) {
							sum += score[1];
						}
						else if (cnt == 3) {
							sum += score[2];
						}
						else {
							sum += score[3];
						}
						break;
					}
					else if (board.mat[u][v] == color) {
						cnt++;
						if (cnt == 4) {
							sum += score[3];
							break;
						}
					}
					else {
						if (cnt == 1) {
							sum += score[4];
						}
						else if (cnt == 2) {
							sum += score[5];
						}
						else if (cnt == 3) {
							sum += score[6];
						}
						else {
							sum += score[3];
						}
						break;
					}
				}
			}
		}
		return sum;
	};
	auto cmp = [&](std::pair<DPoint, int>& A, std::pair<DPoint, int>& B) {
		return A.second > B.second;
	};
	for (int i = 0; i < board.n ; i++) {
		for (int j = 0; j < board.m ; j++) {
			if (board.mat[i][j] != -1) {
				continue;
			}
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
			board.records.push({q[i].first,color});
			int x = board.place(q[i].first,color);
			if (x == 1) {
				board.backtrack();
				q[i].second = 50000;
				return q[i];
			}
			int score = place_min_max_dfs(dep+1).second;
			board.backtrack();
			max_score = std::max(max_score, score);
			q[i].second -= max_score;
		}
		sort(q.begin(),q.end(),cmp);
		return q[0];
	}
}