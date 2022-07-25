//
// Created by wangheng on 2022/7/25.
//

#include <iostream>
#include <vector>
#include "vec_util.h"

using namespace std;

class Solution {
private:
    // line[i][j]: 数字j在第i行是否出现
    bool line[9][9] = {false};
    bool column[9][9] = {false};
    bool block[3][3][9] = {false};

public:
    bool isValid = false;
    void solveSudoku(vector<vector<char>> &board) {
        // 待填充的空间
        vector<pair<int, int>> space;

        // 初始化上面三个记录数组
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    space.emplace_back(i, j);
                    continue;
                }
                // 记录数组从第1行开始。
                int digit = board[i][j] - '0' - 1;
                this->line[i][digit] = this->column[j][digit] = this->block[i / 3][j / 3][digit] = true;
            }
        }
        dfs(space, 0, board);
    }

private:
    void dfs(vector<pair<int, int>> &space, int pos, vector<vector<char>> &board) {
        if (pos == space.size()) {
            this->isValid = true;
            return;
        }
        auto [r, c] = space[pos];
        // isValid为false时代表还有数据等待填入
        for (int i = 0; i < 9 && !this->isValid; i++) {
            // 遍历每个数字，看是否能填充进去
            if (this->line[r][i] ||
                this->column[c][i] ||
                this->block[r / 3][c / 3][i]) {
                continue;
            }
            board[r][c] = i + 1 + '0';
            this->line[r][i] = this->column[c][i] = this->block[r / 3][c / 3][i] = true;
            dfs(space, pos + 1, board);
            this->line[r][i] = this->column[c][i] = this->block[r / 3][c / 3][i] = false;
        }
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    s->solveSudoku(board);
//    if(s->isValid){
    for (vector<char> &v: board) {
        print_vec(v);
    }
//    }
    delete s;
}

int main() {
    testSolution();
    return 0;
}
