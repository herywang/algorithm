#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // 动态规划解法
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1] + matrix[0][i];
        dp[i][0] = dp[i - 1][0] + matrix[i][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}