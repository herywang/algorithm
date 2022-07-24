//
// Created by wangheng on 2021/6/23.
// 有效的数独
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2f9gg/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int line[9][9] = {0};
        int column[9][9] = {0};
        int cell[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0' - 1;
                // 第k个cell
                int k = i / 3 * 3 + j / 3;

                if(line[i][num] == 1 || column[j][num] == 1 || cell[k][num]){
                    return false;
                }
                line[i][num] = 1;
                column[j][num] = 1;
                cell[k][num] = 1;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board =
            {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution* solution = new Solution;
    cout<<solution->isValidSudoku(board)<<endl;
    return 0;
}
