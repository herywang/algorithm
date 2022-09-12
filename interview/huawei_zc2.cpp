/**
 * @file huawei_zc2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#define MAX 9999999

using namespace std;

/**
 * @brief
 *
 * @param board
 * @param x E字母一维坐标
 * @param y E字母二维坐标
 * @param type 当前探索的方向
 * @param lastType 上一次探索的方向，用于判断改变方向
 * @return int
 */
int solve(vector<vector<char>> &board, int x, int y, char type, char lastType, vector<vector<bool>> &isVisited) {
    if (x < 0 || x > board.size() || y < 0 || y > board[0].size()) {
        return 0x1FFFFFFF;
    }
    if (board[x][y] == 'S') {
        return 0;
    }
    if (board[x][y] == 'B') {
        isVisited[x][y] = true;
        int a = ('U' == lastType || lastType == '\0' ? solve(board, x - 1, y, 'U', lastType, isVisited) + 1 : solve(board, x - 1, y, 'U', lastType, isVisited) + 2);
        int b = ('D' == lastType || lastType == '\0' ? solve(board, x + 1, y, 'D', lastType, isVisited) + 1 : solve(board, x + 1, y, 'D', lastType, isVisited) + 2);
        int c = ('L' == lastType || lastType == '\0' ? solve(board, x, y - 1, 'L', lastType, isVisited) + 1 : solve(board, x, y - 1, 'L', lastType, isVisited) + 2);
        int d = ('R' == lastType || lastType == '\0' ? solve(board, x, y + 1, 'R', lastType, isVisited) + 1 : solve(board, x, y + 1, 'R', lastType, isVisited) + 2);
        isVisited[x][y] = false;
        return min(min(a, b), min(c, d));
    } else {
        return 0x1FFFFFFF;
    }
}

int main(int argc, char *argv[]) {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> board(row, vector<char>(col, '0'));
    vector<vector<bool>> isVisited(row, vector<bool>(col, false));
    int x = 0, y = 0;
    for (int i = 0; i < row; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < col; j++) {
            board[i][j] = line[j];
            if (board[i][j] == 'E') {
                x = i;
                y = j;
            }
        }
    }
    int ans1 = min(solve(board, x - 1, y, 'U', '\0', isVisited), solve(board, x + 1, y, 'D', '\0', isVisited));
    int ans2 = min(solve(board, x, y - 1, 'L', '\0', isVisited), solve(board, x, y + 1, 'R', '\0', isVisited));
    cout << min(ans1, ans2) << endl;
    return 0;
}