//
// Created by wangheng on 2022/7/21.
// 统计所有质数

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2){
            return 0;
        }
        // 是否是质数
        vector<bool> primes(n, true);
        for(int i = 2;i*i < n;i++){
            if(primes[i]){
                // 如果当前是素数,将所有其倍数设置成false
                for(int j = i*i;j<n;j+=i){
                    primes[j] = false;
                }
            }
        }
        // 计数
        int cnt = 0;
        for(int i = 2;i<n;i++){
            if(primes[i]){
                cnt ++;
            }
        }
        return cnt;
    }
};

void testSolution(){
    auto s = new Solution;
    cout<<s->countPrimes(10)<<endl;
}

int main() {
    testSolution();
    return 0;
}
