//
// Created by wangheng on 2022/7/28.
// 三角形最小路径和

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int row = triangle.size();
        vector<vector<int>> dp;

        // 初始化dp数组Ò
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 0; i < row; i++) {
            dp.push_back(vector<int>(i + 1, 0));
            dp[i][0] = prev1 + triangle[i][0];
            dp[i][i] = prev2 + triangle[i][i];
            prev1 = dp[i][0];
            prev2 = dp[i][i];
        }
        for (int i = 2; i < row; i++) {
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        // 查找dp最后一行的最小值
        int minValue = INT_MAX;
        for (int i = 0; i < row; i++) {
            if (dp[row - 1][i] < minValue) {
                minValue = dp[row - 1][i];
            }
        }
        return minValue;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> triangle1 = {{-10}};
    int res = s->minimumTotal(triangle1);
    cout << res << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
