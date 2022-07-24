//
// Created by wangheng on 2021/10/10.
// 跳跃游戏

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            if(i>k)return false;
            k = max(k, i+nums[i]);
        }
        return true;
    }
};

int main() {
    auto s = new Solution;
    vector<int> nums = {2,3,1,1,4};
    cout<<s->canJump(nums)<<endl;
    return 0;
}
