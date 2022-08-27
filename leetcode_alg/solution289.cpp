//
// Created by wangheng on 2022/8/17.
// 生命游戏

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool cellStatus(int i, int j, vector<vector<int>> &board) {
        int row = board.size(), col = board[0].size();
        if (i >= 0 && i < row) {
            if (j >= 0 && j < col) {
                return board[i][j] == 1;
            }
        }
        return false;
    }
public:
    void gameOfLife(vector<vector<int>> &board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> copyBoard(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                copyBoard[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 周围活着的细胞数量
                int count = 0;
                count += cellStatus(i - 1, j - 1, board) ? 1 : 0;
                count += cellStatus(i - 1, j, board) ? 1 : 0;
                count += cellStatus(i - 1, j + 1, board) ? 1 : 0;
                count += cellStatus(i, j - 1, board) ? 1 : 0;
                count += cellStatus(i, j + 1, board) ? 1 : 0;
                count += cellStatus(i + 1, j - 1, board) ? 1 : 0;
                count += cellStatus(i + 1, j, board) ? 1 : 0;
                count += cellStatus(i + 1, j + 1, board) ? 1 : 0;

                if(count < 2){
                    copyBoard[i][j] = 0;
                }else if((count == 2 || count ==3) && board[i][j]==1){
                    copyBoard[i][j] = 1;
                }else if(count > 3 && board[i][j] == 1){
                    copyBoard[i][j] = 0;
                }else if(count == 3 && board[i][j] == 0){
                    copyBoard[i][j] = 1;
                }
            }
        }
        board = copyBoard;
    }
};

int main() {

    return 0;
}
