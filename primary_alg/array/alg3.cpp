//
// Created by wangheng on 2021/6/22.
// 判断是否存在重复元素
#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        if(nums.size()<2){
            return false;
        }
        sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};

int main() {
    Solution* solution = new Solution;
    vector<int> vec = {1,1,1,3,3,4,3,2,4,2};
    cout<<solution->containsDuplicate(vec)<<endl;
    return 0;
}

