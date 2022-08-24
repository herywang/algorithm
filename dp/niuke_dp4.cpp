//
// Created by wangheng on 2022/8/23.
// 最小花费爬楼梯

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &costs, int N){
    int* dp = new int[N+1]{0};
    // dp[i]表示到第i个台阶需要的最小花费代价
    for(int i = 2;i<=N;i++){
        dp[i] = min(dp[i-2]+costs[i-2], dp[i-1]+costs[i-1]);
    }
    int ans = dp[N];
    delete[] dp;
    return ans;
}

int main(int argc, char *argv[]) {
    int N;
    cin>>N;
    vector<int> costs(N+1, 0);
    for(int i = 0;i<N;i++){
        int &i1 = costs[i];
        cin>>i1;
    }
    cout<<solution(costs, N)<<endl;
    return 0;
}