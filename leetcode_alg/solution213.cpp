//
// Created by wangheng on 2022/7/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        // 不打劫第一个
        vector<int> dp1(nums.size()+1, 0);
        // 不打劫最后一个
        vector<int> dp2(nums.size()+1, 0);

        // dp[i] 表示前 i-1 个最大价值
        // 不打劫第一个，最后一个可以打劫也可以不打劫，视情况而定
        dp1[1] = 0;
        for(int i = 2;i<=nums.size();i++){
            dp1[i] = max(dp1[i-2] + nums[i-1], dp1[i-1]);
        }

        // 打劫第一个, 不打劫最后一个
        dp2[1] = nums[0];
        nums[nums.size()-1] = 0;
        for(int i = 2;i<=nums.size();i++){
            dp2[i] = max(dp2[i-2] + nums[i-1], dp2[i-1]);
        }
        return max(dp1[nums.size()], dp2[nums.size()]);
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> nums = {1, 2,3,1};
    cout<<s->rob(nums)<<endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
