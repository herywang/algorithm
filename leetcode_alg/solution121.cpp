//
// Created by wangheng on 2022/8/7.
// 买股票的最佳时机, 单调栈

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        // 最后面设置一个哨兵元素
        prices.push_back(INT32_MIN);
        // 单调栈
        vector<int> s;
        int maxProfit = 0;
        for(int i = 0;i<prices.size();i++){
            while (!s.empty() && prices[i] < s.back()){
                maxProfit = max(maxProfit, s.back()-s.front());
                s.pop_back();
            }
            s.emplace_back(prices[i]);
        }
        return maxProfit;
    }
};

void testSolution(){
    auto s = new Solution;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s->maxProfit(prices)<<endl;
    delete s;
}

int main() {
    testSolution();
    return 0;
}
