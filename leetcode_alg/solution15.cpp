//
// Created by wangheng on 2021/6/17.
// 三数之和相加等于0， 三个数不重复
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        if (nums[0] > 0) return ans;
        int i = 0;
        sort(nums.begin(), nums.end());
        while(i<nums.size()){
            if(nums[i]>0)break;
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 相同的元素不应再被计算一次
                    while(left < right and nums[left]==nums[left+1])
                        left++;
                    while(left<right and nums[right]==nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
            // 避免nums[i]作为一个重复的数出现
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};

int main() {

    return 0;
}

