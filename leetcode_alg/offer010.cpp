/**
 * @file offer010.cpp
 * @author your name (you@domain.com)
 * @brief 剑指offer II 010 和为 k的连续子数组个数
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k) {
    int left = 0;
    int right = left + 1;
    int ans = 0;
    int tmp = nums[left];
    while (right < nums.size() || left < nums.size()) {
        if (tmp < k) {
            if (right == nums.size()) {
                return ans;
            }
            tmp += nums[right++];
        } else if (tmp == k) {
            ans++;
            tmp -= nums[left++];
        } else {
            // tmp >k
            tmp -= nums[left++];
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> nums1 = {-1, -1, 1};
    cout << subarraySum(nums1, 0) << endl;
    return 0;
}