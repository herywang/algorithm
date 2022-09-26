#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (flag) {
            dp[i][0] = 0;
            continue;
        }
        if (board[i][0] == 1) {
            dp[i][0] = 0;
            flag = true;
        } else {
            dp[i][0] = 1;
        }
    }
    flag = false;
    for (int i = 0; i < m; i++) {
        if (flag) {
            dp[0][i] = 0;
            continue;
        }
        if (board[0][i] == 1) {
            dp[0][i] = 0;
            flag = true;
        } else {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (board[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}