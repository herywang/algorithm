/**
 * @file solution698.cpp
 * @author your name (you@domain.com)
 * @brief 划分为k个相等的子集
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

bool dfs(vector<int> &nums, int target, vector<bool> &isVisited) {
    if (target == 0) {
        return true;
    }
    if (target < 0) {
        return false;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (isVisited[i]) {
            continue;
        }
        if (target - nums[i] == 0) {
            return true;
        }
        isVisited[i] = true;
        dfs(nums, target - nums[i], isVisited);
        isVisited[i] = false;
    }
    return false;
}

bool canPartitionKSubsets(vector<int> &nums, int k) {
    assert(k > 0);

    if (k == 1) {
        return true;
    }
    int sum = 0;
    for (int &v : nums) {
        sum += v;
    }
    if (sum % k != 0) {
        return false;
    }
    int subSum = sum / k;
    vector<bool> isVisited(nums.size(), false);
    for (int i = 0; i < nums.size(); i++) {
        // if (dfs(nums, i, subSum)) {
        //     return true;
        // }
    }
    return false;
}

int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    bool res = canPartitionKSubsets(nums, 4);
    cout << res << endl;
    return 0;
}