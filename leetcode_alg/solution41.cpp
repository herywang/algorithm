//
// Created by wangheng on 2022/7/25.
// 缺失的第一个正整数

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0){
                set.insert(nums[i]);
            }
        }
        for(int i = 1;i<=nums.size();i++){
            if(set.find(i) == set.end()){
                // 没找到，缺失了
                return i;
            }
        }
        return nums.size()+1;
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> nums = {7,8,9,11,12};
    vector<int> nums2 = {3,4,-1,1};
    cout<<s->firstMissingPositive(nums2)<<endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
