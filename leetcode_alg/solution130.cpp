/**
 * @file solution130.cpp
 * @author your name (you@domain.com)
 * @brief 被围绕的区域
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
private:
    int row;
    int col;
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= this->row || y < 0 || y >= this->col || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }

public:
    void solve(vector<vector<char>> &board) {
        this->row = board.size();
        this->col = board[0].size();
        // 遍历边界，将边界与外界连通的O标记为A
        for (int i = 0; i < this->col; i++) {
            dfs(board, 0, i);
            dfs(board, this->row - 1, i);
        }
        for (int i = 0; i < this->row; i++) {
            dfs(board, i, 0);
            dfs(board, i, this->col - 1);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    auto s = new Solution;
    vector<vector<char>> board = {
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'}};
    s->solve(board);
    for (auto &_v : board) {
        print_vec(_v);
    }
    delete s;
    return 0;
}