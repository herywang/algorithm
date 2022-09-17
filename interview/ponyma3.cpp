#include <iostream>
#include <vector>

using namespace std;

bool inBoard(int n, int m, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

/**
 * @brief
 *
 * @param board
 * @param n 行
 * @param m 列
 * @return int
 */
int solve(vector<string> &board, int n, int m) {
    int maxAns = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i;
            int y = j;
            int ans = 0;
            vector<vector<bool>> isVisited(n, vector<bool>(m, false));
            while (inBoard(n, m, x, y) && !isVisited[x][y]) {
                ans += 1;
                isVisited[x][y] = true;
                if (board[x][y] == '^') {
                    x--;
                } else if (board[x][y] == 'v') {
                    x++;
                } else if (board[x][y] == '<') {
                    y--;
                } else if (board[x][y] == '>') {
                    y++;
                }
            }
            maxAns = max(maxAns, ans);
        }
    }
    return maxAns;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board;
    for (int i = 0; i < n; i++) {
        string _str;
        cin >> _str;
        board.emplace_back(_str);
    }
    cout << solve(board, n, m) << endl;
    return 0;
}