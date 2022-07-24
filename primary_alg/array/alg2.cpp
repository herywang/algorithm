//
// Created by wangheng on 2021/6/22.
// 旋转数组问题, 将数组元素向右旋转k位数
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2skh7/
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < 2 || k == 0 || k == nums.size()){
            return;
        }
        if(k>nums.size()){
            k = k % nums.size();
        }
        int mid = (0 + nums.size()-1) >> 1;
        int tmp;
        // 首先整体旋转一遍
        for(int i = 0;i<=mid;i++){
            tmp = nums[i];
            nums[i] = nums[nums.size()-1-i];
            nums[nums.size()-1-i] = tmp;
        }
        // 接下来左k位数旋转一遍
        mid = (0+k-1) >> 1;
        for(int i = 0;i<=mid;i++){
            tmp = nums[i];
            nums[i] = nums[k-1-i];
            nums[k-1-i] = tmp;
        }
        // 最后右边(nums.size() - k)位再旋转一下
        mid = (k+nums.size()-1) >> 1;
        for(int i = k;i<=mid;i++){
            tmp = nums[i];
            nums[i] = nums[nums.size()-1-i+k];
            nums[nums.size()-1-i+k] = tmp;
        }
    }
};

int main(){
    Solution* solution = new Solution;
    vector<int> vec = {1,2,3,4,5,6,7};
    solution->rotate(vec, 3);
    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;

}
