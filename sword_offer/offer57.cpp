//
// Created by wangheng on 2021/7/21.
// 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int> &nums, int target) {
        vector<int> ans;
        if(nums.size()<2){
            return ans;
        }
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int t = nums[l] + nums[r];
            if(t == target){
                ans.push_back(nums[l]);
                ans.push_back(nums[r]);
                return ans;
            }else if(t > target){
                r--;
            }else{
                l++;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
