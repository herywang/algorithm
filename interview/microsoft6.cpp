//
// Created by wangheng on 2022/8/26.
//
#include <iostream>
#include <vector>

using namespace std;

int sol(std::vector<int> vec, int M) {
    std::vector<int> mod(M);
    for (int p = 0; p < M; ++p) {
        mod[p] = 0;
    }
    for (int i: vec) {
        mod[(std::abs(vec[i]) % M)] = mod[(std::abs(vec[i]) % M)] + 1;
    }
    std::sort(mod.begin(), mod.end());
    return mod[M - 1];
}

int main(void) {
    std::cout << sol({-3, -2, 1, 0, 8, 7, 1}, 3) << std::endl; // 4
    std::cout << sol({7, 1, 11, 8, 4, 10}, 8) << std::endl; // 2
    return 0;
}