//
// Created by wangheng on 2022/8/23.
// 跳台阶问题

#include <iostream>

using namespace std;

int solution(int n){
    if(n<3){
        return n;
    }
    int* dp = new int[n+1]{0};
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(int argc, char *argv[]) {
    int N;
    cin>>N;
    cout<<solution(N)<<endl;
    return 0;
}