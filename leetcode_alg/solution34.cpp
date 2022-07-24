//
// Created by wangheng on 2021/7/4.
// 在排好序的数据中查找第一个和最后一个出现的位置

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if(nums.size() == 0){
            return ans;
        }
        int i = 0;
        for(;i<nums.size();i++){
            if(nums[i] == target){
                ans[0] = i;
                ans[1] = i;
                break;
            }
        }
        if(ans[0] != -1){
            for(i = i+1;i<nums.size();i++){
                if(nums[i] > target){
                    return ans;
                }else{
                    // 等于target
                    ans[1] = i;
                }
            }
        }
        return ans;
    }
};

int main() {

    Solution* solution = new Solution;
    vector<int> nums = {1,2,3,4,4,4,5,5,6,7};
    vector<int> result = solution->searchRange(nums, 4);
    cout<<result[0]<<result[1]<<endl;
    return 0;
}
