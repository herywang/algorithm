/**
 * @file solution152.cpp
 * @author your name (you@domain.com)
 * @brief 乘积最大的连续子数组
 * @version 0.1
 * @date 2022-08-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int N = nums.size();
        vector<int> maxDp(nums);
        vector<int> minDp(nums);

        for (int i = 1; i <= N; i++) {
            maxDp[i] = max(maxDp[i - 1] * nums[i], max(minDp[i - 1] * nums[i], nums[i]));
            minDp[i] = min(minDp[i - 1] * nums[i], min(maxDp[i - 1] * nums[i], nums[i]));
        }
        return *max_element(maxDp.begin(), maxDp.end());
    }
};

int main(int argc, char *argv[]) {
    auto s = new Solution;
    vector<int> nums = {2, 3, -2, 4};
    cout << s->maxProduct(nums) << endl;
    delete s;
    return 0;
}