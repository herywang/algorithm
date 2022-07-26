//
// Created by wangheng on 2022/7/26.
// 大疆笔试题-1

#include <iostream>
#include <vector>
#include <math.h>

#define PI 3.1415927

using namespace std;

double HanWin(short n, int N) {
    return 0.5 * (1 - cos(2 * PI * n / N));
}

double f(short xn, int N, int n) {
    return xn * HanWin(n, N);
}

int main() {
    int N;
    cin >> N;
    if (N < 16 || N > 512) {
        return -1;
    }
    short *xn = new short[N];
    for (int i = 0; i < N; i++) {
        cin >> xn[i];
    }

    for(int n = 0;n<=N;n++){
        cout<<"n="<<n<<endl;
        for(int i = 0;i<N;i++){
            cout<<int(f(xn[i], N, n)+0.5)<<" ";
        }
        cout<<endl;
    }

    return 0;
}
