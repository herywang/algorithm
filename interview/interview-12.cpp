//
// Created by wangheng on 2022/7/19.
// 矩阵中的路径

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>> &board, string word) {
        this->row = board.size();
        if (row == 0) {
            return false;
        }
        this->col = board[0].size();
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }


    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int k) {
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k]) {
            return false;
        }
        // 最后一个字母匹配成功
        if (k == word.size() - 1) {
            return true;
        }
        // 遍历过一次，将board中的字符设置成 "已经访问过" 防止重复遍历
        board[i][j] = '\0';
        bool res = dfs(board, word, i - 1, j, k + 1) ||
                   dfs(board, word, i + 1, j, k + 1) ||
                   dfs(board, word, i, j - 1, k + 1) ||
                   dfs(board, word, i, j + 1, k + 1);
        // 此操作相当于使用了 isUsed数组
        board[i][j] = word[k];
        return res;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string str = "ABCCED";
    cout<<s->exist(board, str)<<endl;
}

int main() {
    testSolution();
    return 0;
}
