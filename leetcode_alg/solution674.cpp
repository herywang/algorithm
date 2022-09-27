/**
 * @file solution674.cpp
 * @author your name (you@domain.com)
 * @brief 最长连续递增序列 长度
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int> &nums) {
    assert(nums.size() > 0);
    if (nums.size() == 1) {
        return 1;
    }
    int left = 0;
    int right = left + 1;
    int ans = 1;
    while (right < nums.size()) {
        if (nums[right] > nums[right - 1]) {
            right++;
            ans = max(ans, right - left);
        } else {
            ans = max(ans, right - left);
            left = right;
            right++;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 3, 5, 7};
    cout << findLengthOfLCIS(nums) << endl;
    return 0;
}