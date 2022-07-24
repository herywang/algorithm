//
// Created by wangheng on 2021/6/22.
// 加一操作
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2cv1c/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.size() < 1) {
            return digits;
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] != 9){
                digits[i] += 1;
                return digits;
            }else{
                digits[i] =0;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};

int main() {
    Solution* solution = new Solution;
    vector<int> v = {9,9,9,9};
    const vector<int> &ans = solution->plusOne(v);
    for(int i :ans){
        cout<<i;
    }
    cout<<endl;
    return 0;
}
