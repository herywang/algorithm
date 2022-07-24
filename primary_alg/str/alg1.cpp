//
// Created by wangheng on 2021/6/23 .
// 翻转字符串
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnhbqj/

#include "vec_util.h"
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        if(s.size()<2){
            return;
        }
        int len = s.size();
        int mid = len >> 1;
        char t;
        for(int i = 0;i<mid;i++){
            t = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = t;
        }
    }
};

int main() {
    Solution* solution = new Solution;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    solution->reverseString(str);
    print_vec(str);
    return 0;
}
