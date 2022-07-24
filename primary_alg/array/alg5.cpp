//
// Created by wangheng on 2021/6/22.
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x21ib6/
// 判断只出现一次的那个数字

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int reduce = 0;
        for(int num:nums){
            reduce = reduce ^ num;
        }
        return reduce;
    }
};
int main() {
    vector<int> vec = {3,4,5,4,5,3,1};
    Solution *solution = new Solution;
    cout<<solution->singleNumber(vec)<<endl;
    return 0;
}
