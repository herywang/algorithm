//
// Created by wangheng on 2022/8/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int solution(vector<int>& values){
        if(values.size()==0){
            return 0;
        }
        if(values.size()==1){
            return values[0];
        }
        // 动态规划状态转移存储数组,dp[i]标识前i件物品的最大价值
        vector<int> dp(values.size()+1);
        dp[0] = 0;
        dp[1] = values[0];
        for(int i = 1;i<values.size();i++){
            dp[i+1] = max(dp[i-1]+values[i], dp[i]);
        }
        return dp[values.size()];
    }
};

int main() {
    vector<int> numbers;
    int number;
    while(true){
        cin>>number;
        numbers.push_back(number);
        if(cin.get() == '\n'){
            break;
        }
    }
    auto s = new Solution;
    cout<<s->solution(numbers)<<endl;
    delete s;
    return 0;
}
