//
// Created by wangheng on 2022/7/20.
// 打家劫舍
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int *dp = new int[nums.size()+1]{0};
        dp[1] = nums[0];
        for(int i = 2;i<=nums.size();i++){
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[nums.size()];
    }
};

void testSolution(){
    Solution *pSolution = new Solution;
    vector<int> nums = {1,2,3,1};
    cout<<pSolution->rob(nums)<<endl;
}

int main() {
    testSolution();
    return 0;
}
