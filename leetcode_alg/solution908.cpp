/**
 * @file solution908.cpp
 * @author your name (you@domain.com)
 * @brief 最小差值
 * @version 0.1
 * @date 2022-10-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

int smallestRangeI(vector<int> &nums, int k) {
    int maxVal = nums[0];
    int minVal = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
    }
    return max(maxVal - minVal - 2 * k, 0);
}

int main() {
    vector<int> nums = {1, 3, 6, 9};
    int ans = smallestRangeI(nums, 2);
    cout << ans << endl;
    return 0;
}