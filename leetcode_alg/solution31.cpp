//
// Created by wangheng on 2021/6/30.
// 下一个排列
// 算法简要描述： 从后往前找第一个相对升序的序列[i, j]
// 然后再从[j, end) 找到第一个比A[i] 大的元素 A[k]
// 交换A[i] 和 A[k]
// 最后再将A[j] ~ A[end]变成升序排列

#include <iostream>
#include <vector>
#include "algorithm"
#include "vec_util.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size()-1;
        for(;i>0;i--){
            // 从后往前找到第一个递增序列
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        if(i==0){
            // 没有找到递增序列，说明整个数字串都是递减的，那就将其改为最小值
            sort(nums.begin(), nums.end());
        }else{
            int min = INT32_MAX;
            int k;
            for(int l = i;l<nums.size();l++){
                if(nums[l] > nums[i-1]){
                    if(nums[l] < min){
                        min = nums[l];
                        k = l;
                    }
                }
            }
            // 找到 A[i], A[k], A[j] 之后，交换A[i], A[k], 然后将A[j~end] 变为升序排列即可
            int t = nums[i-1];
            nums[i-1] = nums[k];
            nums[k] = t;
            sort(nums.begin()+i, nums.end());
        }
    }
};

int main() {
    Solution* solution = new Solution;
//    vector<int> nums = {1,2,3,8,5,7,6,4};
    vector<int> nums = {1,2,3};
    solution->nextPermutation(nums);
    print_vec(nums);
    return 0;
}
