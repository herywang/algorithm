//
// Created by wangheng on 2022/8/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.size() < 1 || obstacleGrid[0].size() < 1) {
            return 0;
        }
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        int dp[row][col];

        // 初始化dp数组
        bool hasObstacle = false;
        for (int i = 0; i < col; i++) {
            if (hasObstacle) {
                dp[0][i] = 0;
            } else {
                if (obstacleGrid[0][i] == 1) {
                    // 障碍物
                    dp[0][i] = 0;
                    hasObstacle = true;
                } else {
                    dp[0][i] = 1;
                }
            }
        }
        hasObstacle = false;
        for (int i = 0; i < row; i++) {
            if (hasObstacle) {
                dp[i][0] = 0;
            } else {
                if (obstacleGrid[i][0] == 1) {
                    dp[i][0] = 0;
                    hasObstacle = true;
                } else {
                    dp[i][0] = 1;
                }
            }
        }
        // 更新dp数组
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    cout << s->uniquePathsWithObstacles(obstacleGrid) << endl;
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}