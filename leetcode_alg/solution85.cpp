/**
 * @file solution85.cpp
 * @author your name (you@domain.com)
 * @brief 最大矩形
 * @version 0.1
 * @date 2022-09-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        if (matrix[0].size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        // 动态规划计算最大矩形面积
        dp[0][0] = matrix[0][0] == 1 ? 1 : 0;
        int ans = dp[0][0];
        for (int i = 1; i < row; i++) {
            dp[i][0] = matrix[i][0] == 1 ? (dp[i - 1][0] + 1) : 0;
            ans = max(dp[i][0], ans);
        }
        for (int i = 1; i < col; i++) {
            dp[0][i] = matrix[0][i] == 1 ? (dp[0][i - 1] + 1) : 0;
            ans = max(dp[i][0], ans);
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] = 0) {
                    dp[i][j] = 0;
                } else {
                    int a = 1, b = 1, c = 1;
                    if (matrix[i][j - 1] == 1) {
                        a = dp[i][j - 1] + 1;
                    }
                    if (matrix[i - 1][j] == 1) {
                        b = dp[i - 1][j] + 1;
                    }
                    if (matrix[i - 1][j - 1] == 1 && matrix[i - 1][j] == 1 && matrix[i][j - 1] == 1) {
                        c = dp[i - 1][j - 1];
                    }
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    return 0;
}