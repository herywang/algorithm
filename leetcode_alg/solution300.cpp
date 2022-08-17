//
// Created by wangheng on 2022/8/17.
// 最长递增子序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int *dp = new int[nums.size()];
        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    // 第i个元素比前面的大
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

void testSolution() {
    auto s = new Solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s->lengthOfLIS(nums) << endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
