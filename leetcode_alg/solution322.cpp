/**
 * @file solution322.cpp
 * @author your name (you@domain.com)
 * @brief 零钱兑换
 * @version 0.1
 * @date 2022-09-13
 *  记忆化搜索 + 动态规划 两种方式实现
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 回溯+记忆化搜索方法解决
 */
class Solution {
private:
    vector<int> tmpStatus;
    int dfs(vector<int> &coins, int amount) {
        if (amount == 0) {
            return 0;
        } else if (amount < 0) {
            return -1;
        }
        if (tmpStatus[amount - 1] != 0) {
            return tmpStatus[amount - 1];
        }
        int minRes = INT_MAX;
        for (int &coin : coins) {
            int res = dfs(coins, amount - coin);
            if (res >= 0 && res < minRes) {
                minRes = res + 1;
            }
        }
        this->tmpStatus[amount - 1] = minRes == INT_MAX ? -1 : minRes;
        return this->tmpStatus[amount - 1];
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        this->tmpStatus.resize(amount, 0);
        return this->dfs(coins, amount);
    }
};

/**
 * @brief 动态规划方式解决
 */
class Solution2 {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        int *dp = new int[amount + 1];
        int ans;
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int minVal = INT_MAX;
            for (int &coin : coins) {
                if (i - coin >= 0) {
                    minVal = min(minVal, dp[i - coin] + 1);
                }
            }
            dp[i] = minVal;
        }
        ans = dp[amount];
        delete[] dp;
        return ans == INT_MAX ? -1 : ans;
    }
};

void testSolution() {
    Solution *pS = new Solution;
    vector<int> coins = {1, 2, 5};
    cout << pS->coinChange(coins, 11) << endl;
    delete pS;
}

void testSolution2() {
    Solution2 *ps2 = new Solution2;
    vector<int> coins = {1, 2, 5};
    cout << ps2->coinChange(coins, 11) << endl;
    delete ps2;
}

int main() {
    // testSolution();
    testSolution2();
    return 0;
}