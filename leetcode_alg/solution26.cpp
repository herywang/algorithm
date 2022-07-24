//
// Created by wangheng on 2021/6/21.
// O(1)空间复杂度删除数组中重复元素
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <2){
            return nums.size();
        }
        int j = 0;
        for(int i = 1;i<nums.size();i++){
            if(nums[j] != nums[i]){
                nums[++j] = nums[i];
            }
        }
        return ++j;
    }
};
int main(){
    Solution *s = new Solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int len = s->removeDuplicates(nums);
    for(int i = 0;i<len;i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}

