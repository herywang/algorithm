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

    }
};

int main(int argc, char *argv[]) {

    return 0;
}