//
// Created by wangheng on 2021/6/26.
// 爬楼梯，动态规划入门

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<3){
            return n;
        }
        int l1 = 1;
        int l2 = 2;
        for(int i = 3;i<=n;i++){
            int t = l1 + l2;
            l1 = l2;
            l2 = t;
        }
        return l2;
    }
};

int main() {
    Solution *solution = new Solution;
    cout<<solution->climbStairs(5)<<endl;
    return 0;
}
