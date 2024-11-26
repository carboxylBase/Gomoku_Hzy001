#include "Board.hpp"
#include <iostream>

/*
    Board.
*/

Board::Board(int N, int M) {
    n = N;
    m = M;
    mat.resize(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(m, -1);
    }
}

void Board::print_in_console() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

void Board::backtrack() {
    if (records.empty()) return;
    mat[records.top().first.x][records.top().first.y] = -1;
    records.pop();
    return;
}

/*
    Gomoku Board.
*/

GomokuBoard::GomokuBoard(int N, int M) : Board(N, M) {}

int GomokuBoard::place(DPoint pos, int color) {
    if (pos.x >= n || pos.y >= m) {
        return -1;
    }
    if (mat[pos.x][pos.y] != -1) {
        return -1;
    }
    mat[pos.x][pos.y] = color;
    if (color == 1) {
        sum_white++;
    }
    else {
        sum_black++;
    }
    int vx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
    int vy[8] = { 0, 1, -1, 1, 0, -1, 1, -1 };
    int cnt[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < 8; i++) {
        int u = pos.x, v = pos.y;
        for (int j = 0;; j++) {
            u += vx[i], v += vy[i];
            if (u < 0 || u >= n || v < 0 || v >= m) {
                break;
            }
            if (mat[u][v] == color) {
                cnt[i]++;
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (cnt[i] + cnt[i + 4] >= 4) {
            return 1;
        }
    }
    return 0;
}
