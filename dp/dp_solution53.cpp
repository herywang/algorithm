//
// Created by wangheng on 2021/6/26.
// solution53: 最大连续子序列和

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int dp[nums.size()];
        dp[0] = nums[0];
        int max_num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            max_num = max(dp[i], max_num);
        }
        return max_num;
    }
};

int main() {
    Solution *solution = new Solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int i = solution->maxSubArray(nums);
    cout<<i<<endl;
    delete solution;
    return 0;
}
