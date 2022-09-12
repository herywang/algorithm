#include <iostream>
#include <vector>

using namespace std;

struct Cell {
    int val;   //最大正方形边长值
    int sum;   //最大正方形面积
    bool flag; //是否包含负数
};

/**
 * @brief
 *
 * @param board 输入矩阵
 * @param m 行数
 * @param n 列数
 * @return int 返回结果
 */
int solve(vector<vector<int>> &board, int m, int n) {
    if (m == 0 || n == 0) {
        return -1;
    }
    int ans = -1;
    int dp[m + 1][n + 1];
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 初始化dp数组
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] >= 0) {
                if (i >= 1 && j >= 1) {
                    // 最小边长
                    int minLen = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    dp[i][j] = minLen;
                    if (minLen > 1) {
                        int _t = 0;
                        for (int k = 0; k < minLen; k++) {
                            for (int _k = 0; _k < minLen; _k++) {
                                _t += board[i - k][j - _k];
                            }
                        }
                        ans = max(ans, _t);
                    } else {
                        ans = max(ans, board[i][j]);
                    }
                } else {
                    dp[i][j] = 1;
                    ans = max(ans, board[i][j]);
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> board(m, vector<int>(n, 0));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < m; y++) {
                cin >> board[x][y];
            }
        }
        cout << solve(board, m, n) << endl;
    }

    return 0;
}