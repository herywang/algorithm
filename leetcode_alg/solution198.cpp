//
// Created by wangheng on 2022/8/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int* dp = new int[n+1]{0};
        dp[1] = nums[0];
        for(int i = 1;i<n;i++){
            dp[i+1] = max(dp[i-1]+nums[i], dp[i]);
        }
        return dp[n];
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> nums = {1,2,3,1};
    cout<<s->rob(nums)<<endl;
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}