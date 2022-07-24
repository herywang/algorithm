//
// Created by wangheng on 2022/7/13.
// 剪绳子

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int cuttingRope(int num){
    if(num == 0){
        return 0;
    }
    if(num == 2){
        return 1;
    }
    if(num == 3){
        return 2;
    }
    int n = num % 3;
    int c = num / 3;
    if(n == 0){
        return pow(3,c);
    }else if(n == 1){
        return 2*2*pow(3, c-1);
    }else{
        return 2 * pow(3, c);
    }
}

int main() {
    cout<<cuttingRope(10)<<endl;
    return 0;
}
