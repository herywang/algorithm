//
// Created by wangheng on 2021/6/22.
// 初级算法: 2: 买卖股票问题
// https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2zsx1/
// 考察贪心算法
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        } else {
            vector<int> tmp;
            for (int i = 1; i < prices.size(); i++) {
                tmp.push_back(prices[i] - prices[i - 1]);
            }
            int total = 0;
            for (int a:tmp) {
                if (a > 0) {
                    total += a;
                }
            }
            return total;
        }
    }
};

int main() {
    Solution *solution = new Solution;
    vector<int> prices = {7,1,5,1,9,3,6,4};
    cout<<"最大收益:"<<solution->maxProfit(prices)<<endl;
    return 0;
}
