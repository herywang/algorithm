//
// Created by wangheng on 2021/6/22.
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2y0c2/
// 两个数组的交集
// 相关算法: 排序, 双指针

#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if(nums1.size() == 0 || nums2.size() == 0){
            return ans;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        while(i<nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2};
    Solution* s = new Solution;
    const vector<int> &ans = s->intersect(nums1, nums2);
    for(int n:ans){
        cout<<n<<" ";
    }
    cout<<endl;
    return 0;
}
