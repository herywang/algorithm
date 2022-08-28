/**
 * @file solution64.cpp
 * @author wangheng
 * @brief
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022 wangheng
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.size() < 1 || grid[0].size() < 1) {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < col; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    int res = s->minPathSum(grid);
    cout << res << endl;
    delete s;
}

int main() {
    testSolution();
    cout << "hello world" << endl;
    return 0;
}