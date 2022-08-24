//
// Created by wangheng on 2022/8/23.
// 跳台阶拓展问题

#include <iostream>

using namespace std;

int solution(int N){
    int* dp = new int[N+1]{0};
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i<=N;i++){
        int sum = 0;
        for(int j = 1;j<i;j++){
            sum += dp[j];
        }
        dp[i] = sum+1;
    }
    return dp[N];
}

int main(int argc, char *argv[]) {
    int N;
    cin>>N;
    cout<<solution(N)<<endl;
    return 0;
}