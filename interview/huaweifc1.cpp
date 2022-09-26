//
// Created by wangheng on 2022/9/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> &list, int threadCount) {
    int ans = 0;
    int dp[threadCount];

    for (int i = 0; i < threadCount; i++) {
        dp[i] = list[i];
    }

    for (int i = threadCount; i < list.size(); i++) {
        int _min = 9999;
        int _minIndex = 0;
        for (int j = 0; j < threadCount; j++) {
            if (_min >= dp[j]) {
                _min = dp[j];
                _minIndex = j;
            }
        }
        // 判断 同一位置和是否相等，相等则直接清零
        for (int j = 0; j < threadCount - 1; j++) {
            for (int k = j + 1; k < threadCount; k++) {
                if (dp[k] == dp[j]) {
                    dp[k] = 0;
                    dp[j] = 0;
                }
            }
        }
        for (int j = 0; j < threadCount; j++) {
            dp[j] -= _min;
        }
        ans += _min;
        dp[_minIndex] += list[i];
    }
    int maxVal = 0;
    for (int i = 0; i < threadCount; i++) {
        maxVal = max(maxVal, dp[i]);
    }
    ans += maxVal;
    return ans;
}

int main(int argc, char *argv[]) {
    vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8};
    int threadCount = 3;
    sort(number.begin(), number.end());
    cout << solve(number, threadCount) << endl;
    return 0;
}